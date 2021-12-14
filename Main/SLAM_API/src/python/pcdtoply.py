import sys
import os
import open3d as o3d

if __name__ == "__main__":
    pcd_file = sys.argv[1]
    ply_file = sys.argv[2]

    pcd = o3d.io.read_point_cloud(pcd_file)
    o3d.io.write_point_cloud(ply_file, pcd)