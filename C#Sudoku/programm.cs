

using System.Text;
using System;
using Projekt.Generator;
using Projekt.Converter;


namespace Projekt.Main
{
    public class Program
    {
        public static void Main()
        {
            Encoding.RegisterProvider(CodePagesEncodingProvider.Instance);
            Createpdftable pdfTable = new Createpdftable();
            pdfTable.createfile();
        }
    }
}



