using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using manage_dll;


namespace cls_seg_csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            string s = "E:/Data/solder/test/neg/324.jpg";
            manage_cls cls_info = new manage_cls(s);
            Console.WriteLine("class_id:{0},prob:{1}", cls_info.cls_id, cls_info.cls_prob);
            Console.ReadLine();
            string s1= "E:/Data/solder_seg/test/1_000010.jpg";
            //manage_seg seg_info = new manage_seg();
            manage_seg seg_info = new manage_seg(s1);
            int[] info = seg_info.get_reult();
            for(int i=0;i<65536;++i)
            {
                Console.WriteLine("seg_info[{0}]:{1}",i,info[i]);
            }
            
           
            Console.ReadLine();
        }
    }
}
