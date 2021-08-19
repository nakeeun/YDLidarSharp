using System;
using YDLidarSharp;

namespace YDLidar_scan
{
    class YDLidar_scan
    {
        static void Main(string[] args)
        {
            var ydl = new YDLidarSDK();
            string[] port_list = YDLidarSDK.GetLidarPorts();
            ydl.SerialPort = "COM3";
            Console.WriteLine(ydl.SerialPort);
            /* YDLidar G2 parameter setting */
            ydl.SerialBaudrate = 230400;
            ydl.SingleChannel = false;
            ydl.ScanFrequency = 10.0F;
            ydl.LidarType = LidarType.TRIANGLE;
            ydl.SampleRate = 5;
            ydl.AbnormalCheckCount = 2;
            ydl.Reversion = true;
            ydl.Inverted = true;
            ydl.AutoReconnect = true;
            ydl.FixedResolution = true;
            ydl.MaxAngle = 180.0F;
            ydl.MinAngle = -180.0F;
            ydl.MaxRange = 64.0F;
            ydl.MinRange = 0.01F;

            ////////////////////////////////////////

            bool ret = ydl.Initialize();  
            if (ret == true)
            {
                ret = ydl.TurnOn();
                LaserScan raw_scan;
                raw_scan = ydl.GetData();
                int scan_size = raw_scan.LaserPoints.Count;
                double[,] p2c = new double[scan_size, 2];
                p2c = pol2cart(raw_scan, scan_size, p2c);
            }
            ret = ydl.TurnOff();
        }
        public static double[,] pol2cart(LaserScan scan, int scan_size,  double[,] p2c) //convert polar coordinate to Cartesian Coordinates
        {
            for (int i = 0; i < scan_size; i++)
            {
                double angle = (double)scan.LaserPoints[i].Angle;
                double range = (double)scan.LaserPoints[i].Range;
                p2c[i, 0] = range * Math.Cos(angle);
                p2c[i, 1] = range * Math.Sin(angle);

            }
            return p2c;
        }
    }
}
