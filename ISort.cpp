#include "ISort.h"
#include"Algoritm.h"



double** SelectionSort::Sort(double** Matrix, int n, int m) 
{
   std::vector< std::vector <NegativeNunb>> negative;
   
   for (int i = 0; i < n; i++)
       negative.push_back(std::vector <NegativeNunb>{});
    name = "SelectionSort";
    double** new_matrix = new double* [n];
    for (int k = 0; k < n; k++) {
        new_matrix[k] = new double[m];
    }
    copy(new_matrix, Matrix, n, m);
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m;j++)
        {
            if (new_matrix[i][j] < 0)
                negative[i].emplace_back(NegativeNunb(new_matrix[i][j], i, j));
        }
    for (int q = 0; q <  static_cast<int>(negative.size()); q++)
    {
        if (negative[q].size() == 0)
            continue;
        for (int i = 0; i <  static_cast<int>(negative[q].size()) - 1; i++)
        {
            double tmp = negative[q][i].numb;
            int tmpid = i;
            for (int j = i + 1; j <  static_cast<int>(negative[q].size()); j++)
            {
                comparison_counter++;
                if (negative[q][tmpid].numb > negative[q][j].numb)
                {
                    tmp = negative[q][j].numb;
                    tmpid = j;
                }
            }
            if (tmpid != i)
            {
                permutation_counter++;
                std::swap(negative[q][i].numb, negative[q][tmpid].numb);
            }
        }
    }
    for (int i = 0; i <  static_cast<int>(negative.size());i++)
        for (int j = 0; j <  static_cast<int>(negative[i].size()); j++)
        {
            new_matrix[negative[i][j].i][negative[i][j].j] = negative[i][j].numb;
        }
   
    return new_matrix;
   
}

double** InsertionSort::Sort(double** Matrix, int n, int m) 
{
    std::vector< std::vector <NegativeNunb>> negative;

    for (int i = 0; i < n; i++)
        negative.push_back(std::vector <NegativeNunb>{});
    name = "InsertionSort";
    double** new_matrix = new double* [n];
    for (int k = 0; k < n; k++) {
        new_matrix[k] = new double[m];
    }
    copy(new_matrix, Matrix, n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (new_matrix[i][j] < 0)
                negative[i].emplace_back(NegativeNunb(new_matrix[i][j], i, j));
        }
    for (int q = 0; q <  static_cast<int>(negative.size()); q++)
        for (int k = 1; k <  static_cast<int>(negative[q].size()); k++)
        {
            double temp = negative[q][k].numb;
            int j = k - 1;
            comparison_counter++;
            while (j >= 0 && temp < negative[q][j].numb)
            {
                comparison_counter++;
                permutation_counter++;
                negative[q][j + 1].numb = negative[q][j].numb;
                j--;
                if (j == 0)
                    comparison_counter --;

            }
            negative[q][j + 1].numb = temp;
        }
    for (int i = 0; i <  static_cast<int>(negative.size()); i++)
        for (int j = 0; j <  static_cast<int>(negative[i].size()); j++)
        {
            new_matrix[negative[i][j].i][negative[i][j].j] = negative[i][j].numb;
        }
    return new_matrix;
}

double** ShellSort::Sort(double** Matrix, int n, int m)
{
    std::vector< std::vector <NegativeNunb>> negative;

    for (int i = 0; i < n; i++)
        negative.push_back(std::vector <NegativeNunb>{});
    name = "ShellSort";
  
    double** new_matrix = new double* [n];
    for (int k = 0; k < n; k++) {
        new_matrix[k] = new double[m];
    }
    copy(new_matrix, Matrix, n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (new_matrix[i][j] < 0)
                negative[i].emplace_back(NegativeNunb(new_matrix[i][j], i, j));
        }
    
    for (int q = 0; q <  static_cast<int>(negative.size()); q++)
    {
        for (int gap = static_cast<int>(negative[q].size())/2; gap > 0; gap /= 2) {
            for (int i = gap; i <  static_cast<int>(negative[q].size()); i++) {

                double temp = negative[q][i].numb;
                int k;
                comparison_counter++;
                for (k = i; k >= gap && negative[q][k - gap].numb > temp; k -= gap) {
                    negative[q][k].numb = negative[q][k - gap].numb; permutation_counter++;
                    if (k == gap)
                        comparison_counter--;
                }
                negative[q][k].numb = temp;
            }
        }
    }
    for (int i = 0; i <  static_cast<int>(negative.size()); i++)
        for (int j = 0; j <  static_cast<int>(negative[i].size()); j++)
        {
            new_matrix[negative[i][j].i][negative[i][j].j] = negative[i][j].numb;
        }
    return new_matrix;
}
double** BubbleSort::Sort(double** Matrix, int n, int m)
{
    std::vector< std::vector <NegativeNunb>> negative;

    for (int i = 0; i < n; i++)
        negative.push_back(std::vector <NegativeNunb>{});
    name = "BubbleSort";
    
    double** new_matrix = new double* [n];
    for (int k = 0; k < n; k++) {
        new_matrix[k] = new double[m];
    }
    copy(new_matrix, Matrix, n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (new_matrix[i][j] < 0)
                negative[i].emplace_back(NegativeNunb(new_matrix[i][j], i, j));
        }
    
   
    for (int q = 0; q <  static_cast<int>(negative.size()); q++){
        if (negative[q].size() == 0)
            continue;
        for (int j = 0; j < (static_cast<int>(negative[q].size()) - 1); j++) {
            bool flag = true;
            for (int k = 0; k < m - (j + 1); k++) {
				if (k == static_cast<int>(negative[q].size()) - 1)
					break;
                comparison_counter++;
                if (negative[q][k].numb > negative[q][k + 1].numb) {
                    flag = false;
                    swap(negative[q][k].numb, negative[q][k + 1].numb);
                    permutation_counter++;
                }
            }
            if (flag) {
                break;
            }
        }
    }
    for (int i = 0; i <  static_cast<int>(negative.size()); i++)
        for (int j = 0; j <  static_cast<int>(negative[i].size()); j++)
        {
            new_matrix[negative[i][j].i][negative[i][j].j] = negative[i][j].numb;
        }
    return new_matrix;
}

void QuickSortMat::QuickSort(std::vector <NegativeNunb>& arr, int start, int end)
{
    if (start < end) {
        int p = Partition(arr, start, end);
        QuickSort(arr, start, p - 1);
        QuickSort(arr, p + 1, end);
    }
    
}

int QuickSortMat::Partition(std::vector <NegativeNunb>& arr, int start, int end)
{
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i) {
        comparison_counter++;
        if (arr[i].numb < arr[pivot].numb) {
            permutation_counter++;
            swap(arr[i].numb, arr[j].numb);
            ++j;
        }
    }
   
        swap(arr[j].numb, arr[pivot].numb);
        if(j != pivot)
            permutation_counter ++;
  
    return j;

}

double** QuickSortMat::Sort(double** Matrix, int n, int m)
{
    std::vector< std::vector <NegativeNunb>> negative;
    for (int i = 0; i < n; i++)
        negative.push_back(std::vector <NegativeNunb>{});
    name = "QuickSort";
    
    double** new_matrix = new double* [n];
    for (int k = 0; k < n; k++) {
        new_matrix[k] = new double[m]; 
    }
   copy(new_matrix, Matrix, n, m);

   for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
       {
           if (new_matrix[i][j] < 0)
               negative[i].emplace_back(NegativeNunb(new_matrix[i][j], i, j));
       }
   for (int i = 0; i <  static_cast<int>(negative.size()); i++) {
           QuickSort(negative[i], 0, static_cast<int>(negative[i].size() - 1));
   }
   for (int i = 0; i <  static_cast<int>(negative.size()); i++)
       for (int j = 0; j <  static_cast<int>(negative[i].size()); j++)
       {
           new_matrix[negative[i][j].i][negative[i][j].j] = negative[i][j].numb;
       }
   return new_matrix;
}

std::string ISort::GetName()
{
    return name;
}

int ISort::GetComparison()
{
    return comparison_counter;
}

int ISort::GetPermutation()
{
    return permutation_counter;
}
