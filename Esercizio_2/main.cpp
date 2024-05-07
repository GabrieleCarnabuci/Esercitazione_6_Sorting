#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include "SortingAlgorithm.hpp"

using namespace SortLibrary;
using namespace std::chrono;

double tempoMedioBS(vector<double>& v, const unsigned int & n)
{
    vector<double> tempo;
    double tempomedio = 0.0;
    tempo.reserve(n);


    for(unsigned int i = 0; i < n; i++)
    {
        steady_clock::time_point t_begin = steady_clock::now();
        BubbleSort(v);
        steady_clock::time_point t_end = steady_clock::now();

        double el = duration_cast<microseconds>(t_end - t_begin).count();
        tempo.push_back(el);
    }

    for(unsigned int i = 0; i < tempo.size(); i++)
        tempomedio += tempo[i];

    tempomedio = tempomedio / tempo.size();

    return tempomedio;

}

double tempoMedioMS(vector<double>& v, const unsigned int & n)
{
    vector<double> tempo;
    double tempomedio = 0.0;
    tempo.reserve(n);

    for(unsigned int i = 0; i < n; i++)
    {
        steady_clock::time_point t_begin = steady_clock::now();
        MergeSort(v);
        steady_clock::time_point t_end = std::chrono::steady_clock::now();

        double el = duration_cast<microseconds>(t_end - t_begin).count();
        tempo.push_back(el);
    }

    for(unsigned int i = 0; i < tempo.size(); i++)
        tempomedio += tempo[i];

    tempomedio = tempomedio / tempo.size();

    return tempomedio;
}

int main(int argc, char ** argv)
{
    unsigned int n = 10;
    unsigned int nn = 200;
    unsigned int dim = stoi(argv[1]);
    vector<double> v(dim);

    cout << "CASO : vettori ordinati con n = 10" << endl;

    iota(v.begin(),v.end(), 0);

    cout << "Tempo medio usando BubbleSort (microsecondi): " << tempoMedioBS(v, n) << endl;

    cout << "Tempo medio usando MergeSort (microsecondi):  " << tempoMedioMS(v, n) << endl;
    cout << endl;


    cout << "CASO: vettori ordinati con n = 200" << endl;

    iota(v.begin(),v.end(), 0);

    cout << "Tempo medio usando BubbleSort (microsecondi): " << tempoMedioBS(v, nn) << endl;

    cout << "Tempo medio usando MergeSort (microsecondi): " << tempoMedioMS(v, nn) << endl;
    cout << endl;


    cout << "CASO: vettori casuali con n = 10" << endl;

    for(unsigned int  i = 0; i < dim; i++)
    {
        v[i] = rand() % 1000;
    }

    cout << "Tempo medio usando BubbleSort (microsecondi): " << tempoMedioBS(v, n) << endl;

    cout << "Tempo medio usando MergeSort (microsecondi): " << tempoMedioMS(v, n) << endl;
    cout << endl;


    cout << "CASO: vettori casuali con n = 200" << endl;

    for(unsigned int  i = 0; i < dim; i++)
    {
        v[i] = rand() % 1000;
    }

    cout << "Tempo medio usando BubbleSort (microsecondi): " << tempoMedioBS(v, nn) << endl;

    cout << "Tempo medio usando MergeSort (microsecondi): " << tempoMedioMS(v, nn) << endl;
    cout << endl;

    return 0;
}
