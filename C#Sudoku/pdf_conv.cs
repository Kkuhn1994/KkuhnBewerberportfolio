using System;
using PdfSharpCore.Pdf;
using PdfSharpCore.Drawing;
using Projekt.Generator;
//using Projekt.Generator;

//using Internal;

namespace Projekt.Converter
{
    
    public class Createpdftable
    {
        public int iterator;

        public Createpdftable()
        {
            iterator = 1;
        }
        public void createfile()
        {
            string namestring = $"sudoku Nr {iterator}";
            Console.WriteLine(namestring);
            PdfDocument document = new PdfDocument();
            document.Info.Title = namestring;
            PdfPage page = document.AddPage();
            XGraphics gfx = XGraphics.FromPdfPage(page);
            XFont font = new XFont("Verdana", 20, XFontStyle.Regular);

            int marginX = 120;
            int marginY = 100;
            int cellSize = 40;

            SudokuGenerator generator = new SudokuGenerator();
            generator.GenerateSudoku();
            int[,]? sudoku = generator.Sudoku;
            for (int index = 0; index <= 9; index++)
            {
                gfx.DrawLine(XPens.Black, marginX, marginY + index * cellSize, marginX + 9 * cellSize, marginY + index * cellSize);
                gfx.DrawLine(XPens.Black, marginX + index * cellSize, marginY, marginX + index * cellSize, marginY + 9 * cellSize);
            }

            for (int index = 0; index <= 9; index += 3)
            {
                gfx.DrawLine(new XPen(XColors.Black, 2), marginX, marginY + index * cellSize, marginX + 9 * cellSize, marginY + index * cellSize);
                gfx.DrawLine(new XPen(XColors.Black, 2), marginX + index * cellSize, marginY, marginX + index * cellSize, marginY + 9 * cellSize);
            }

    
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    int number = sudoku[i, j];
                    if (number != 0)
                    {
                        string blockContent = number.ToString();
                        double x = marginX + j * cellSize;
                        double y = marginY + i * cellSize;
                        gfx.DrawString(blockContent, font, XBrushes.Black, new XRect(x, y, cellSize, cellSize), XStringFormats.Center);

                    }
                }
            }
            document.Save("sudoku.pdf");
        }
    }
}
