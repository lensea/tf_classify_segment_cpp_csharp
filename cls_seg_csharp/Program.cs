using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ManageDll;


namespace ClsSegCsharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "E:/Data/solder/test/neg/324.jpg";
            ManageCls cls_info = new ManageCls(str);
            Console.WriteLine("class_id:{0},prob:{1}", cls_info.cls_id, cls_info.cls_prob);
            Console.ReadLine();
            string str1= "E:/Data/solder_seg/test/1_000010.jpg";
            //ManageSeg seg_info = new ManageSeg();
            ManageSeg seg_info = new ManageSeg(str1);
            int[] info = seg_info.GetReult();
            for(int i=0;i<65536;++i)
            {
                Console.WriteLine("seg_info[{0}]:{1}",i,info[i]);
            }
            
           
            Console.ReadLine();
        }
    }
}
