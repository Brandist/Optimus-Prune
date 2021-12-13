import sys
import os
import open3d as o3d

def convertPLYtoPCD(ply_file, pcd_file):
    pcd = o3d.io.read_point_cloud(ply_file)
    o3d.io.write_point_cloud(pcd_file, pcd)

if __name__ == "__main__":

    ply_file = sys.argv[1]
    pcd_file = sys.argv[2]

    convertPLYtoPCD(ply_file, pcd_file)