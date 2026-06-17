    #include <iostream>
    #include <vector>
    #include <string>

    void readMatrix(std::vector<std::vector <int> > &matrix)
    {
        for(int row = 0; row < matrix.size(); row++)
        {
            for(int col = 0; col < matrix[0].size(); col++)
            {
                std::cin >> matrix[row][col];
            }
        }
    }

    void reverseDiagonal (const std::vector< std::vector <int> > &matrix, int row, int col)
    {
        while(row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size())
        {
            std::cout << matrix[row][col] << " ";
            row--;
            col++;
        }

        std::cout << std::endl;
    }

    int main()
    {
        int rows, cols;
        std::cin >> rows >> cols;
        std::vector< std::vector<int> > matrix (rows,std::vector<int>(cols, 0));

        readMatrix(matrix);

        for(int col = matrix[0].size() - 1; col >=0; col--)
            reverseDiagonal(matrix, matrix.size() - 1, col);

        for(int row = matrix.size() - 2; row >= 0; row--)
            reverseDiagonal(matrix, row, 0);

        return 0;
    }