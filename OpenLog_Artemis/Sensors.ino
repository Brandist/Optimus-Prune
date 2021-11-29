//Query each enabled sensor for its most recent data
void getData()
{
  measurementCount++;
  measurementTotal++;

  char tempData[50];
  char tempData1[16];
  char tempData2[16];
  char tempData3[16];
  outputData[0] = '\0'; //Clear string contents

  if (settings.logRTC)
  {
    //Code written by @DennisMelamed in PR #70
    char timeString[37];
    getTimeString(timeString); // getTimeString is in timeStamp.ino
    strcat(outputData, timeString);
  }

  if (settings.logA11)
  {
    unsigned int analog11 = analogRead(11);

    if (settings.logAnalogVoltages == true)
    {
      float voltage = analog11 * 2 / 16384.0;
      olaftoa(voltage, tempData1, 2, sizeof(tempData1) / sizeof(char));
      sprintf(tempData, "%s,", tempData1);
    }
    else
      sprintf(tempData, "%d,", analog11);

    strcat(outputData, tempData);
  }

  if (settings.logA12)
  {
    unsigned int analog12 = analogRead(12);

    if (settings.logAnalogVoltages == true)
    {
      float voltage = analog12 * 2 / 16384.0;
      olaftoa(voltage, tempData1, 2, sizeof(tempData1) / sizeof(char));
      sprintf(tempData, "%s,", tempData1);
    }
    else
      sprintf(tempData, "%d,", analog12);

    strcat(outputData, tempData);
  }

  if (settings.logA13)
  {
    unsigned int analog13 = analogRead(13);

    if (settings.logAnalogVoltages == true)
    {
      float voltage = analog13 * 2 / 16384.0;
      olaftoa(voltage, tempData1, 2, sizeof(tempData1) / sizeof(char));
      sprintf(tempData, "%s,", tempData1);
    }
    else
      sprintf(tempData, "%d,", analog13);

    strcat(outputData, tempData);
  }

  if (settings.logA32)
  {
    unsigned int analog32 = analogRead(32);

    if (settings.logAnalogVoltages == true)
    {
      float voltage = analog32 * 2 / 16384.0;
      olaftoa(voltage, tempData1, 2, sizeof(tempData1) / sizeof(char));
      sprintf(tempData, "%s,", tempData1);
    }
    else
      sprintf(tempData, "%d,", analog32);

    strcat(outputData, tempData);
  }

  if (settings.logVIN)
  {
    float voltage = readVIN();
    olaftoa(voltage, tempData1, 2, sizeof(tempData1) / sizeof(char));
    sprintf(tempData, "%s,", tempData1);
    strcat(outputData, tempData);
  }

  if (online.IMU)
  {
    //printDebug("getData: online.IMU = " + (String)online.IMU + "\r\n");

    if (settings.imuUseDMP == false)
    {
      if (myICM.dataReady())
      {
        //printDebug("getData: myICM.dataReady = " + (String)myICM.dataReady() + "\r\n");

        myICM.getAGMT(); //Update values

        if (settings.logIMUAccel)
        {
          olaftoa(myICM.accX(), tempData1, 2, sizeof(tempData1) / sizeof(char));
          olaftoa(myICM.accY(), tempData2, 2, sizeof(tempData2) / sizeof(char));
          olaftoa(myICM.accZ(), tempData3, 2, sizeof(tempData3) / sizeof(char));
          sprintf(tempData, "%s,%s,%s,", tempData1, tempData2, tempData3);
          strcat(outputData, tempData);
        }
        if (settings.logIMUGyro)
        {
          olaftoa(myICM.gyrX(), tempData1, 2, sizeof(tempData1) / sizeof(char));
          olaftoa(myICM.gyrY(), tempData2, 2, sizeof(tempData2) / sizeof(char));
          olaftoa(myICM.gyrZ(), tempData3, 2, sizeof(tempData3) / sizeof(char));
          sprintf(tempData, "%s,%s,%s,", tempData1, tempData2, tempData3);
          strcat(outputData, tempData);
        }
        if (settings.logIMUMag)
        {
          olaftoa(myICM.magX(), tempData1, 2, sizeof(tempData1) / sizeof(char));
          olaftoa(myICM.magY(), tempData2, 2, sizeof(tempData2) / sizeof(char));
          olaftoa(myICM.magZ(), tempData3, 2, sizeof(tempData3) / sizeof(char));
          sprintf(tempData, "%s,%s,%s,", tempData1, tempData2, tempData3);
          strcat(outputData, tempData);
        }
        if (settings.logIMUTemp)
        {
          olaftoa(myICM.temp(), tempData1, 2, sizeof(tempData1) / sizeof(char));
          sprintf(tempData, "%s,", tempData1);
          strcat(outputData, tempData);
        }
      }
      //else
      //{
      //  printDebug("getData: myICM.dataReady = " + (String)myICM.dataReady() + "\r\n");
      //}
    }
    else
    {
      myICM.readDMPdataFromFIFO(&dmpData);
      while (myICM.status == ICM_20948_Stat_FIFOMoreDataAvail)
      {
        myICM.readDMPdataFromFIFO(&dmpData); // Empty the FIFO - make sure data contains the most recent data
      }
      if (settings.imuLogDMPQuat6)
      {
        olaftoa(((double)dmpData.Quat6.Data.Q1) / 1073741824.0, tempData1, 5, sizeof(tempData1) / sizeof(char));
        olaftoa(((double)dmpData.Quat6.Data.Q2) / 1073741824.0, tempData2, 5, sizeof(tempData2) / sizeof(char));
        olaftoa(((double)dmpData.Quat6.Data.Q3) / 1073741824.0, tempData3, 5, sizeof(tempData3) / sizeof(char));
        sprintf(tempData, "%s,%s,%s,", tempData1, tempData2, tempData3);
        strcat(outputData, tempData);
      }
      if (settings.imuLogDMPQuat9)
      {
        olaftoa(((double)dmpData.Quat9.Data.Q1) / 1073741824.0, tempData1, 5, sizeof(tempData1) / sizeof(char));
        olaftoa(((double)dmpData.Quat9.Data.Q2) / 1073741824.0, tempData2, 5, sizeof(tempData2) / sizeof(char));
        olaftoa(((double)dmpData.Quat9.Data.Q3) / 1073741824.0, tempData3, 5, sizeof(tempData3) / sizeof(char));
        sprintf(tempData, "%s,%s,%s,%d,", tempData1, tempData2, tempData3, dmpData.Quat9.Data.Accuracy);
        strcat(outputData, tempData);
      }
      if (settings.imuLogDMPAccel)
      {
        sprintf(tempData, "%d,%d,%d,", dmpData.Raw_Accel.Data.X, dmpData.Raw_Accel.Data.Y, dmpData.Raw_Accel.Data.Z);
        strcat(outputData, tempData);
      }
      if (settings.imuLogDMPGyro)
      {
        sprintf(tempData, "%d,%d,%d,", dmpData.Raw_Gyro.Data.X, dmpData.Raw_Gyro.Data.Y, dmpData.Raw_Gyro.Data.Z);
        strcat(outputData, tempData);
      }
      if (settings.imuLogDMPCpass)
      {
        sprintf(tempData, "%d,%d,%d,", dmpData.Compass.Data.X, dmpData.Compass.Data.Y, dmpData.Compass.Data.Z);
        strcat(outputData, tempData);
      }
    }
  }

  //Append all external sensor data on linked list to outputData
  gatherDeviceValues();

  if (settings.logHertz)
  {
    uint64_t currentMillis;

    //If we are sleeping between readings then we cannot rely on millis() as it is powered down
    //Use RTC instead
    currentMillis = bestMillis();
    float actualRate;
    if ((currentMillis - measurementStartTime) < 1) // Avoid divide by zero
      actualRate = 0.0;
    else
      actualRate = measurementCount * 1000.0 / (currentMillis - measurementStartTime);
    olaftoa(actualRate, tempData1, 3, sizeof(tempData) / sizeof(char));
    sprintf(tempData, "%s,", tempData1);
    strcat(outputData, tempData);
  }

  if (settings.printMeasurementCount)
  {
    sprintf(tempData, "%d,", measurementTotal);
    strcat(outputData, tempData);
  }

  strcat(outputData, "\r\n");

  totalCharactersPrinted += strlen(outputData);
}

//Read values from the devices on the node list
//Append values to outputData
void gatherDeviceValues()
{
  char tempData[100];
  char tempData1[20];

  //Step through list, printing values as we go
  node *temp = head;
  while (temp != NULL)
  {
    sensorData[0] = '\0'; //Clear string contents

    //If this node successfully begin()'d
    if (temp->online == true)
    {
      char gnssPortNumber[3];
      sprintf(gnssPortNumber, "%u", temp->portNumber);
      openConnection(temp->muxAddress, temp->portNumber); //Connect to this device through muxes as needed

      //Switch on device type to set proper class and setting struct
      setQwiicPullups(0); //Disable pullups to minimize CRC issues

      SFE_UBLOX_GNSS *nodeDevice = (SFE_UBLOX_GNSS *)temp->classPtr;
      struct_uBlox *nodeSetting = (struct_uBlox *)temp->configPtr;

      if (nodeSetting->log == true)
      {
        if (nodeSetting->logDate)
        {
          char gnssDayStr[3];
          char gnssMonthStr[3];
          char gnssYearStr[5];
          int gnssDay = nodeDevice->getDay();
          int gnssMonth = nodeDevice->getMonth();
          int gnssYear = nodeDevice->getYear();
          if (gnssDay < 10)
            sprintf(gnssDayStr, "0%d", gnssDay);
          else
            sprintf(gnssDayStr, "%d", gnssDay);
          if (gnssMonth < 10)
            sprintf(gnssMonthStr, "0%d", gnssMonth);
          else
            sprintf(gnssMonthStr, "%d", gnssMonth);
          sprintf(gnssYearStr, "%d", gnssYear);
          if (settings.americanDateStyle == true)
          {
            sprintf(tempData, "%s/%s/%s,", gnssMonthStr, gnssDayStr, gnssYearStr);
          }
          else
            sprintf(tempData, "%s/%s/%s,", gnssDayStr, gnssMonthStr, gnssYearStr);
          strcat(sensorData, tempData);
        }
        if (nodeSetting->logTime)
        {
          int adjustedHour = nodeDevice->getHour();
          if (settings.hour24Style == false)
            if (adjustedHour > 12) adjustedHour -= 12;

          char gnssHourStr[3];
          char gnssMinStr[3];
          char gnssSecStr[3];
          char gnssMillisStr[4];
          int gnssMin = nodeDevice->getMinute();
          int gnssSec = nodeDevice->getSecond();
          int gnssMillis = nodeDevice->getMillisecond();

          if (adjustedHour < 10)
            sprintf(gnssHourStr, "0%d", adjustedHour);
          else
            sprintf(gnssHourStr, "%d", adjustedHour);
          if (gnssMin < 10)
            sprintf(gnssMinStr, "0%d", gnssMin);
          else
            sprintf(gnssMinStr, "%d", gnssMin);
          if (gnssSec < 10)
            sprintf(gnssSecStr, "0%d", gnssSec);
          else
            sprintf(gnssSecStr, "%d", gnssSec);
          if (gnssMillis < 10)
            sprintf(gnssMillisStr, "00%d", gnssMillis);
          else if (gnssMillis < 100)
            sprintf(gnssMillisStr, "0%d", gnssMillis);
          else
            sprintf(gnssMillisStr, "%d", gnssMillis);

          sprintf(tempData, "%s:%s:%s.%s,", gnssHourStr, gnssMinStr, gnssSecStr, gnssMillisStr);
          strcat(sensorData, tempData);
        }
        if (nodeSetting->logPosition)
        {
          sprintf(tempData, "%d,%d,", nodeDevice->getLatitude(), nodeDevice->getLongitude());
          strcat(sensorData, tempData);
        }
        if (nodeSetting->logAltitude)
        {
          sprintf(tempData, "%d,", nodeDevice->getAltitude());
          strcat(sensorData, tempData);
        }
        if (nodeSetting->logAltitudeMSL)
        {
          sprintf(tempData, "%d,", nodeDevice->getAltitudeMSL());
          strcat(sensorData, tempData);
        }
        if (nodeSetting->logSIV)
        {
          sprintf(tempData, "%d,", nodeDevice->getSIV());
          strcat(sensorData, tempData);
        }
        if (nodeSetting->logFixType)
        {
          sprintf(tempData, "%d,", nodeDevice->getFixType());
          strcat(sensorData, tempData);
        }
        if (nodeSetting->logCarrierSolution)
        {
          sprintf(tempData, "%d,", nodeDevice->getCarrierSolutionType());
          strcat(sensorData, tempData);
        }
        if (nodeSetting->logGroundSpeed)
        {
          sprintf(tempData, "%d,", nodeDevice->getGroundSpeed());
          strcat(sensorData, tempData);
        }
        if (nodeSetting->logHeadingOfMotion)
        {
          sprintf(tempData, "%d,", nodeDevice->getHeading());
          strcat(sensorData, tempData);
        }
        if (nodeSetting->logpDOP)
        {
          sprintf(tempData, "%d,", nodeDevice->getPDOP());
          strcat(sensorData, tempData);
        }
        if (nodeSetting->logiTOW)
        {
          sprintf(tempData, "%d,", nodeDevice->getTimeOfWeek());
          strcat(sensorData, tempData);
        }
      }
      SerialPrintln(sensorData);

      setQwiicPullups(settings.qwiicBusPullUps); //Re-enable pullups

    }
    temp = temp->next;
  }
}

//Step through the node list and print helper text for the enabled readings
void printHelperText(bool terminalOnly)
{
  char helperText[1000];
  helperText[0] = '\0';

  if (settings.logRTC)
  {
    if (settings.logDate)
      strcat(helperText, "rtcDate,");
    if (settings.logTime)
      strcat(helperText, "rtcTime,");
    if (settings.logMicroseconds)
      strcat(helperText, "micros,");
  }

  if (settings.logA11)
    strcat(helperText, "analog_11,");

  if (settings.logA12)
    strcat(helperText, "analog_12,");

  if (settings.logA13)
    strcat(helperText, "analog_13,");

  if (settings.logA32)
    strcat(helperText, "analog_32,");

  if (settings.logVIN)
    strcat(helperText, "VIN,");

  if (online.IMU)
  {
    if (settings.imuUseDMP == false)
    {
      if (settings.logIMUAccel)
        strcat(helperText, "aX,aY,aZ,");
      if (settings.logIMUGyro)
        strcat(helperText, "gX,gY,gZ,");
      if (settings.logIMUMag)
        strcat(helperText, "mX,mY,mZ,");
      if (settings.logIMUTemp)
        strcat(helperText, "imu_degC,");
    }
    else
    {
      if (settings.imuLogDMPQuat6)
        strcat(helperText, "Q6_1,Q6_2,Q6_3,");
      if (settings.imuLogDMPQuat9)
        strcat(helperText, "Q9_1,Q9_2,Q9_3,HeadAcc,");
      if (settings.imuLogDMPAccel)
        strcat(helperText, "RawAX,RawAY,RawAZ,");
      if (settings.imuLogDMPGyro)
        strcat(helperText, "RawGX,RawGY,RawGZ,");
      if (settings.imuLogDMPCpass)
        strcat(helperText, "RawMX,RawMY,RawMZ,");
    }
  }

  //Step through list, printing values as we go
  node *temp = head;
  while (temp != NULL)
  {

    //If this node successfully begin()'d
    if (temp->online == true)
    {
      //Switch on device type to set proper class and setting struct
      switch (temp->deviceType)
      {
        case DEVICE_MULTIPLEXER:
          {
            //No data to print for a mux
          }
          break;
        case DEVICE_LOADCELL_NAU7802:
          {
            struct_NAU7802 *nodeSetting = (struct_NAU7802 *)temp->configPtr;
            if (nodeSetting->log)
              strcat(helperText, "weight(no unit),");
          }
          break;
        case DEVICE_DISTANCE_VL53L1X:
          {
            struct_VL53L1X *nodeSetting = (struct_VL53L1X *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logDistance)
                strcat(helperText, "distance_mm,");
              if (nodeSetting->logRangeStatus)
                strcat(helperText, "distance_rangeStatus(0=good),");
              if (nodeSetting->logSignalRate)
                strcat(helperText, "distance_signalRate,");
            }
          }
          break;
        case DEVICE_GPS_UBLOX:
          {
            struct_uBlox *nodeSetting = (struct_uBlox *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logDate)
                strcat(helperText, "gps_Date,");
              if (nodeSetting->logTime)
                strcat(helperText, "gps_Time,");
              if (nodeSetting->logPosition)
                strcat(helperText, "gps_Lat,gps_Long,");
              if (nodeSetting->logAltitude)
                strcat(helperText, "gps_Alt,");
              if (nodeSetting->logAltitudeMSL)
                strcat(helperText, "gps_AltMSL,");
              if (nodeSetting->logSIV)
                strcat(helperText, "gps_SIV,");
              if (nodeSetting->logFixType)
                strcat(helperText, "gps_FixType,");
              if (nodeSetting->logCarrierSolution)
                strcat(helperText, "gps_CarrierSolution,");
              if (nodeSetting->logGroundSpeed)
                strcat(helperText, "gps_GroundSpeed,");
              if (nodeSetting->logHeadingOfMotion)
                strcat(helperText, "gps_Heading,");
              if (nodeSetting->logpDOP)
                strcat(helperText, "gps_pDOP,");
              if (nodeSetting->logiTOW)
                strcat(helperText, "gps_iTOW,");
            }
          }
          break;
        case DEVICE_PROXIMITY_VCNL4040:
          {
            struct_VCNL4040 *nodeSetting = (struct_VCNL4040 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logProximity)
                strcat(helperText, "prox(no unit),");
              if (nodeSetting->logAmbientLight)
                strcat(helperText, "ambient_lux,");
            }
          }
          break;
        case DEVICE_TEMPERATURE_TMP117:
          {
            struct_TMP117 *nodeSetting = (struct_TMP117 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logTemperature)
                strcat(helperText, "degC,");
            }
          }
          break;
        case DEVICE_PRESSURE_MS5637:
          {
            struct_MS5637 *nodeSetting = (struct_MS5637 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logPressure)
                strcat(helperText, "pressure_hPa,");
              if (nodeSetting->logTemperature)
                strcat(helperText, "temperature_degC,");
            }
          }
          break;
        case DEVICE_PRESSURE_LPS25HB:
          {
            struct_LPS25HB *nodeSetting = (struct_LPS25HB *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logPressure)
                strcat(helperText, "pressure_hPa,");
              if (nodeSetting->logTemperature)
                strcat(helperText, "pressure_degC,");
            }
          }
          break;
        case DEVICE_PHT_BME280:
          {
            struct_BME280 *nodeSetting = (struct_BME280 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logPressure)
                strcat(helperText, "pressure_Pa,");
              if (nodeSetting->logHumidity)
                strcat(helperText, "humidity_%,");
              if (nodeSetting->logAltitude)
                strcat(helperText, "altitude_m,");
              if (nodeSetting->logTemperature)
                strcat(helperText, "temp_degC,");
            }
          }
          break;
        case DEVICE_UV_VEML6075:
          {
            struct_VEML6075 *nodeSetting = (struct_VEML6075 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logUVA)
                strcat(helperText, "uva,");
              if (nodeSetting->logUVB)
                strcat(helperText, "uvb,");
              if (nodeSetting->logUVIndex)
                strcat(helperText, "uvIndex,");
            }
          }
          break;
        case DEVICE_VOC_CCS811:
          {
            struct_CCS811 *nodeSetting = (struct_CCS811 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logTVOC)
                strcat(helperText, "tvoc_ppb,");
              if (nodeSetting->logCO2)
                strcat(helperText, "co2_ppm,");
            }
          }
          break;
        case DEVICE_VOC_SGP30:
          {
            struct_SGP30 *nodeSetting = (struct_SGP30 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logTVOC)
                strcat(helperText, "tvoc_ppb,");
              if (nodeSetting->logCO2)
                strcat(helperText, "co2_ppm,");
              if (nodeSetting->logH2)
                strcat(helperText, "H2,");
              if (nodeSetting->logEthanol)
                strcat(helperText, "ethanol,");
            }
          }
          break;
        case DEVICE_CO2_SCD30:
          {
            struct_SCD30 *nodeSetting = (struct_SCD30 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logCO2)
                strcat(helperText, "co2_ppm,");
              if (nodeSetting->logHumidity)
                strcat(helperText, "humidity_%,");
              if (nodeSetting->logTemperature)
                strcat(helperText, "degC,");
            }
          }
          break;
        case DEVICE_PHT_MS8607:
          {
            struct_MS8607 *nodeSetting = (struct_MS8607 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logHumidity)
                strcat(helperText, "humidity_%,");
              if (nodeSetting->logPressure)
                strcat(helperText, "hPa,");
              if (nodeSetting->logTemperature)
                strcat(helperText, "degC,");
            }
          }
          break;
        case DEVICE_TEMPERATURE_MCP9600:
          {
            struct_MCP9600 *nodeSetting = (struct_MCP9600 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logTemperature)
                strcat(helperText, "thermo_degC,");
              if (nodeSetting->logAmbientTemperature)
                strcat(helperText, "thermo_ambientDegC,");
            }
          }
          break;
        case DEVICE_HUMIDITY_AHT20:
          {
            struct_AHT20 *nodeSetting = (struct_AHT20 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logHumidity)
                strcat(helperText, "humidity_%,");
              if (nodeSetting->logTemperature)
                strcat(helperText, "degC,");
            }
          }
          break;
        case DEVICE_HUMIDITY_SHTC3:
          {
            struct_SHTC3 *nodeSetting = (struct_SHTC3 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logHumidity)
                strcat(helperText, "humidity_%,");
              if (nodeSetting->logTemperature)
                strcat(helperText, "degC,");
            }
          }
          break;
        case DEVICE_ADC_ADS122C04:
          {
            struct_ADS122C04 *nodeSetting = (struct_ADS122C04 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logCentigrade)
                strcat(helperText, "degC,");
              if (nodeSetting->logFahrenheit)
                strcat(helperText, "degF,");
              if (nodeSetting->logInternalTemperature)
                strcat(helperText, "degC,");
              if (nodeSetting->logRawVoltage)
                strcat(helperText, "V*2.048/2^23,");
            }
          }
          break;
        case DEVICE_PRESSURE_MPR0025PA1:
          {
            struct_MPR0025PA1 *nodeSetting = (struct_MPR0025PA1 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->usePSI)
                strcat(helperText, "PSI,");
              if (nodeSetting->usePA)
                strcat(helperText, "Pa,");
              if (nodeSetting->useKPA)
                strcat(helperText, "kPa,");
              if (nodeSetting->useTORR)
                strcat(helperText, "torr,");
              if (nodeSetting->useINHG)
                strcat(helperText, "inHg,");
              if (nodeSetting->useATM)
                strcat(helperText, "atm,");
              if (nodeSetting->useBAR)
                strcat(helperText, "bar,");
            }
          }
          break;
        case DEVICE_PARTICLE_SNGCJA5:
          {
            struct_SNGCJA5 *nodeSetting = (struct_SNGCJA5 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logPM1)
                strcat(helperText, "PM1_0,");
              if (nodeSetting->logPM25)
                strcat(helperText, "PM2_5,");
              if (nodeSetting->logPM10)
                strcat(helperText, "PM10,");
              if (nodeSetting->logPC05)
                strcat(helperText, "PC0_5,");
              if (nodeSetting->logPC1)
                strcat(helperText, "PC1_0,");
              if (nodeSetting->logPC25)
                strcat(helperText, "PC2_5,");
              if (nodeSetting->logPC50)
                strcat(helperText, "PC5_0,");
              if (nodeSetting->logPC75)
                strcat(helperText, "PC7_5,");
              if (nodeSetting->logPC10)
                strcat(helperText, "PC10,");
              if (nodeSetting->logSensorStatus)
                strcat(helperText, "Sensors,");
              if (nodeSetting->logPDStatus)
                strcat(helperText, "PD,");
              if (nodeSetting->logLDStatus)
                strcat(helperText, "LD,");
              if (nodeSetting->logFanStatus)
                strcat(helperText, "Fan,");
            }
          }
          break;
        case DEVICE_VOC_SGP40:
          {
            struct_SGP40 *nodeSetting = (struct_SGP40 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logVOC)
                strcat(helperText, "VOCindex,");
            }
          }
          break;
        case DEVICE_PRESSURE_SDP3X:
          {
            struct_SDP3X *nodeSetting = (struct_SDP3X *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logPressure)
                strcat(helperText, "Pa,");
              if (nodeSetting->logTemperature)
                strcat(helperText, "degC,");
            }
          }
          break;
        case DEVICE_PRESSURE_MS5837:
          {
            struct_MS5837 *nodeSetting = (struct_MS5837 *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logPressure)
                strcat(helperText, "mbar,");
              if (nodeSetting->logTemperature)
                strcat(helperText, "degC,");
              if (nodeSetting->logDepth)
                strcat(helperText, "depth_m,");
              if (nodeSetting->logAltitude)
                strcat(helperText, "alt_m,");
            }
          }
          break;
        case DEVICE_QWIIC_BUTTON:
          {
            struct_QWIIC_BUTTON *nodeSetting = (struct_QWIIC_BUTTON *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logPressed)
                strcat(helperText, "pressS,");
              if (nodeSetting->logClicked)
                strcat(helperText, "clickS,");
              if (nodeSetting->toggleLEDOnClick)
                strcat(helperText, "LED,");
            }
          }
          break;
        case DEVICE_BIO_SENSOR_HUB:
          {
            struct_BIO_SENSOR_HUB *nodeSetting = (struct_BIO_SENSOR_HUB *)temp->configPtr;
            if (nodeSetting->log)
            {
              if (nodeSetting->logHeartrate)
                strcat(helperText, "bpm,");
              if (nodeSetting->logConfidence)
                strcat(helperText, "conf%,");
              if (nodeSetting->logOxygen)
                strcat(helperText, "O2%,");
              if (nodeSetting->logStatus)
                strcat(helperText, "stat,");
              if (nodeSetting->logExtendedStatus)
                strcat(helperText, "eStat,");
              if (nodeSetting->logRValue)
                strcat(helperText, "O2R,");
            }
          }
          break;
        default:
          SerialPrintf2("\nprinterHelperText device not found: %d\r\n", temp->deviceType);
          break;
      }
    }
    temp = temp->next;
  }

  if (settings.logHertz)
    strcat(helperText, "output_Hz,");

  if (settings.printMeasurementCount)
    strcat(helperText, "count,");

  strcat(helperText, "\r\n");

  SerialPrint(helperText);
  if ((terminalOnly == false) && (settings.logData == true) && (online.microSD) && (settings.enableSD && online.microSD))
    sensorDataFile.print(helperText);
}

//If certain devices are attached, we need to reduce the I2C max speed
void setMaxI2CSpeed()
{
  uint32_t maxSpeed = 400000; //Assume 400kHz - but beware! 400kHz with no pull-ups can cause u-blox issues.

  //Search nodes for MCP9600s and Ublox modules
  node *temp = head;
  while (temp != NULL)
  {
    if (temp->deviceType == DEVICE_TEMPERATURE_MCP9600)
    {
      //TODO Are we sure the MCP9600, begin'd() on the bus, but not logged will behave when bus is 400kHz?
      //Check if logging is enabled
      struct_MCP9600 *sensor = (struct_MCP9600*)temp->configPtr;
      if (sensor->log == true)
        maxSpeed = 100000;
    }

    if (temp->deviceType == DEVICE_GPS_UBLOX)
    {
      //Check if i2cSpeed is lowered
      struct_uBlox *sensor = (struct_uBlox*)temp->configPtr;
      if (sensor->i2cSpeed == 100000)
      {
        //printDebug("setMaxI2CSpeed: sensor->i2cSpeed is 100000. Reducing maxSpeed to 100kHz\r\n");
        maxSpeed = 100000;
      }
    }

    temp = temp->next;
  }

  //If user wants to limit the I2C bus speed, do it here
  if (maxSpeed > settings.qwiicBusMaxSpeed)
  {
    //printDebug("setMaxI2CSpeed: maxSpeed is > settings.qwiicBusMaxSpeed. Reducing maxSpeed to " + (String)settings.qwiicBusMaxSpeed + "Hz\r\n");
    maxSpeed = settings.qwiicBusMaxSpeed;
  }

  if (maxSpeed > 200000)
  {
    printDebug("setMaxI2CSpeed: setting qwiic clock speed to " + (String)AM_HAL_IOM_400KHZ + "Hz\r\n");
    qwiic.setClock(AM_HAL_IOM_400KHZ);
  }
  else
  {
    printDebug("setMaxI2CSpeed: setting qwiic clock speed to " + (String)AM_HAL_IOM_100KHZ + "Hz\r\n");
    qwiic.setClock(AM_HAL_IOM_100KHZ);
  }
  for (int i = 0; i < 100; i++) //Allow time for the speed to change
  {
    checkBattery();
    delay(1);
  }
}

//Read the VIN voltage
float readVIN()
{
  // Only supported on >= V10 hardware
#if(HARDWARE_VERSION_MAJOR == 0)
  return(0.0); // Return 0.0V on old hardware
#else
  int div3 = analogRead(PIN_VIN_MONITOR); //Read VIN across a 1/3 resistor divider
  float vin = (float)div3 * 3.0 * 2.0 / 16384.0; //Convert 1/3 VIN to VIN (14-bit resolution)
  vin = vin * settings.vinCorrectionFactor; //Correct for divider impedance (determined experimentally)
  return (vin);
#endif
}