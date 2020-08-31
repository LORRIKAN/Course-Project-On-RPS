using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Threading;

namespace SearchAlgorithm
{
    class Program
    {
        static int filesCnt = 0;
        static int dirCnt = 0;
        static void Main(string[] args)
        {
            System.IO.DirectoryInfo root = new System.IO.DirectoryInfo("C:\\Program Files");
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            WalkDirectoryTree(root);
            stopWatch.Stop();
            // Get the elapsed time as a TimeSpan value.
            TimeSpan ts = stopWatch.Elapsed;

            // Format and display the TimeSpan value.
            string elapsedTime = String.Format("{0:00}:{1:00}:{2:00}.{3:00}",
                ts.Hours, ts.Minutes, ts.Seconds,
                ts.Milliseconds / 10);
            Console.WriteLine("RunTime " + elapsedTime + " files: " + filesCnt + " dirs: " + dirCnt);
        }
        static void WalkDirectoryTree(System.IO.DirectoryInfo root)
        {
            System.IO.FileInfo[] files = null;
            System.IO.DirectoryInfo[] subDirs = null;
            try
            {
                files = root.GetFiles("*.*");
                filesCnt += files.Length;
            }
            catch (UnauthorizedAccessException)
            {}
            try
            {
                subDirs = root.GetDirectories();
                dirCnt += subDirs.Length;
            }
            catch (UnauthorizedAccessException)
            {}
            if (subDirs != null)
                foreach (System.IO.DirectoryInfo dirInfo in subDirs)
                {
                    // Resursive call for each subdirectory.
                    WalkDirectoryTree(dirInfo);
                }
        }
    }
}