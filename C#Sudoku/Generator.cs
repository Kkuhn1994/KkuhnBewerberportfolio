using System;
using System.Data.Common;

namespace Projekt.Generator
{
    public class SudokuGenerator
    {
        private int[,]? _sudoku;

        public int[,] Sudoku
        {
            get { return _sudoku; }
            private set { _sudoku = value; }
        }

        public SudokuGenerator()
        {
            _sudoku = new int[9, 9];
        }

        private int CheckColumn(int column, int number)
        {
            for (int line = 0; line < 9; line++)
            {
                if (number == _sudoku[line, column])
                    return 1;
            }
            return 0;
        }

        private int BlockCheck(int lineNumber, int columnNumber, int number)
        {
            int block = (columnNumber / 3) + 3 * (lineNumber / 3);
            for (int line = 0; line < 9; line++)
            {
                for (int column = 0; column < 9; column++)
                {
                    if ((column / 3) + 3 * (line / 3) == block)
                    {
                        if (_sudoku[line, column] == number)
                        {
                            return 1;
                        }
                    }
                }
            }
            return 0;
        }

        private int CheckLine(int line, int number)
        {
            for (int column = 0; column < 9; column++)
            {
                if (number == _sudoku[line, column])
                    return 1;
            }
            return 0;
        }

        public int[,]? GenerateSudoku(int line = 0, int column = 0)
        {
            Random random = new Random();
            if (column == 9)
            {
                column = 0;
                line++;
            }
            if (line == 9)
            {
                Sudoku = _sudoku;
                return Sudoku;
            }

            int iteration = 0;
            int store;
            int number = random.Next(1, 10);
            store = number;
            while (iteration != 10)
            {
                while (CheckLine(line, number) != 0 || CheckColumn(column, number) != 0
                    || BlockCheck(line, column, number) != 0)
                {
                    number++;
                    if (number == 10)
                        number = 1;
                    if (number == store)
                        return null;
                }
                _sudoku[line, column] = number;
                if (GenerateSudoku(line, column + 1) != null)
                {
                    Sudoku = _sudoku;
                    return Sudoku;
                }
                _sudoku[line, column] = 0;
                iteration++;
            }
            return null;
        }

        public void PrintSudoku()
        {
            for (int line = 0; line < 9; line++)
            {
                for (int column = 0; column < 9; column++)
                {
                    Console.Write(_sudoku[line, column] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}
