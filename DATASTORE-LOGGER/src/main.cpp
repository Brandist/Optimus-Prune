/* Copyright 2008, 2010, Oracle and/or its affiliates.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

There are special exceptions to the terms and conditions of the GPL
as it is applied to this software. View the full text of the
exception in file EXCEPTIONS-CONNECTOR-C++ in the directory of this
software distribution.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

using namespace std;

int main(void)
{
  std::cout << endl;
  std::cout << "Running 'SELECT 'Hello World!' » AS _message'..." << std::endl;

  ifstream ifs("dbconfig.json");
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ifs, obj);
  std::cout << "test1: " << obj["test1"].asString() << std::endl;



  try {
    sql::Driver *driver;
    sql::Connection *con;

    /* Create a connection */
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
    cout << con->isValid() << endl;
    con->setSchema("my_db");

    sql::Statement *stmt;

    stmt = con->createStatement();
    stmt->execute("USE my_db");
    stmt->execute("DROP TABLE IF EXISTS test2");
    stmt->execute("CREATE TABLE test2(id INT, label CHAR(1))");
    stmt->execute("INSERT INTO test2(id, label) VALUES (1, 'a')");

    delete stmt;
    delete con;

  } catch (sql::SQLException &e) {
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  }

  cout << endl;

  return EXIT_SUCCESS;
}

//gcc main.cpp -L/usr/lib -lstdc++ -o program