#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <algorithm>
using namespace std;
using namespace std::chrono;
    
struct Bid {
    string bidderId;
    double amount;      
    long long timestamp; 
    int auctionId;
};

void printBids(const vector<Bid>& v, size_t limit = 10) {
    for (size_t i = 0; i < min(v.size(), limit); ++i)
        cout << "[" << v[i].bidderId << "] $" << v[i].amount
             << " @ " << v[i].timestamp << "\n";
    if (v.size() > limit) cout << "... (" << v.size() << " total)\n";
}

bool loadBids(const string& path, vector<Bid>& out) {
    ifstream f(path);
    if (!f) return false;
    Bid b;
    while (f >> b.bidderId >> b.amount >> b.timestamp >> b.auctionId)
        out.push_back(b);
    return true;
}

void insertionSort(vector<Bid> &v){
    for(int i = 1;i< v.size();i++){
        Bid x = v[i];int pos = i-1;
        while(pos >= 0 && (x.amount < v[pos].amount 
            || (x.amount == v[pos].amount && x.timestamp < v[pos].timestamp))){
            v[pos + 1] = v[pos];
            pos--;
        }
        v[pos + 1] = x;
    }
}

void selectionSort(vector<Bid> &v){
    for(int i =0;i<v.size();i++){
        int pos = i;
        for(int j = i+1;j<v.size();j++){
            if(v[j].amount > v[pos].amount){
                pos = j;
            }
        }
        swap(v[i],v[pos]);
    }
}

void InterchangeSort(vector<Bid> &v, int n,int comp,int swaps)
{
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            comp++;
            if (v[i].amount > v[j].amount)
            {
                Bid temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                swaps++;
            }
        }
    }
    cout << "So comparison: " << comp << " " << "So swaps: " << swaps; 
}

bool bubbleSort(vector<Bid> &v){
    
    for(int i = 0;i<v.size();i++){
        int swaped = 0;
        for(int j = 0;j < v.size()-1-i;j++){
            if(v[j].amount > v[j+1].amount){
                Bid temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                swaped = 1;
            }
        }
        if(!swaped) {
            return true;
        }
    }
    return false;
}
int partition(vector<Bid> &v, int low, int high)
{
    Bid pivot = v[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (v[j].amount < pivot.amount || v[j].amount == pivot.amount && v[j].timestamp < pivot.timestamp)
        {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[high]);

    return i + 1;
}

void medianOfThree(vector<Bid> &v, int low, int mid, int high)
{
    if ((v[low].amount < v[mid].amount && v[mid].amount < v[high].amount || 
        v[low].amount == v[mid].amount && v[mid].amount == v[high].amount && 
        v[low].timestamp < v[mid].timestamp && v[mid].timestamp < v[high].timestamp ) ||
        (v[high].amount < v[mid].amount && v[mid].amount < v[low].amount ||
        v[high].amount == v[mid].amount && v[mid].amount == v[low].amount
        && v[high].timestamp < v[mid].timestamp && v[mid].timestamp < v[low].timestamp))
    {
        swap(v[mid], v[high]);
    }
    else if ((v[mid].amount < v[low].amount && v[low].amount < v[high].amount || v[mid].amount == v[low].amount && v[low].amount == v[high].amount 
        && v[mid].timestamp < v[low].timestamp && v[low].timestamp < v[high].timestamp) ||
        (v[high].amount < v[low].amount && v[low].amount < v[mid].amount || v[high].amount == v[low].amount && v[low].amount == v[mid].amount) &&
        v[high].timestamp < v[low].timestamp && v[low].timestamp < v[mid].timestamp)
    {
        swap(v[low], v[high]);
    }
}

void quickSort(vector<Bid> &v, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        medianOfThree(v, low, mid, high);

        int p = partition(v, low, high);

        quickSort(v, low, p - 1);
        quickSort(v, p + 1, high);
    }
}

void quickSortWrapper(vector<Bid>& v)
{
    if (!v.empty())
        quickSort(v, 0, v.size() - 1);
}

bool isSorted(vector<Bid> v){
    for(long long i = 1;i<v.size();i++){
        if(v[i].amount < v[i-1].amount || v[i].amount == v[i-1].amount && v[i].timestamp < v[i-1].timestamp){
            return false;
        }
    }
    return true;
}

void nhapData(vector<Bid> &v,int n){
    v.resize(n);
    for(int i = 0;i<n;i++){
        cout << "Nhap BibberID: ";
        cin >> v[i].bidderId;
        cout << "Nhap amount: ";
        cin >> v[i].amount;
        cout  << "Nhap timestamp: ";
        cin >> v[i].timestamp;
        cout << "Nhap auctionld";
        cin >> v[i].auctionId;
    }
}

int main(){
    int n;
    cin >> n;
    vector<Bid> v(n),v1,v2,v3;
    for(int i = 0;i<n;i++){
        cout << "Nhap BibberID: ";
        cin >> v[i].bidderId;
        cout << "Nhap amount: ";
        cin >> v[i].amount;

        cout  << "Nhap timestamp: ";
        cin >> v[i].timestamp;

        cout << "Nhap auctionld";
        cin >> v[i].auctionId;
    }
    cout << "\n";
    insertionSort(v);
    printBids(v);
    cout << "\n";
    nhapData(v1,n);
    selectionSort(v1);
    printBids(v1,n);
    cout << "\n";
    nhapData(v2,n);
    if(!bubbleSort(v2)){
        cout << "Unstable";
    }
    else cout << "Stable";
    cout << "\n";
    nhapData(v3,n);
    InterchangeSort(v3,n,0,0);
    cout << "\n";

    vector<Bid> Vn;

    const int N = 100000;

    Vn.reserve(N);

    mt19937 rng(19937);

    uniform_real_distribution<double> amountDist(1.0, 100000.0);
    uniform_int_distribution<long long> timeDist(1, 1000000000);
    uniform_int_distribution<int> auctionDist(1, 1000);

    for (int i = 0; i < N; i++)
    {
        Bid b;

        b.bidderId = "B" + to_string(i);
        b.amount = amountDist(rng);
        b.timestamp = timeDist(rng);
        b.auctionId = auctionDist(rng);

        Vn.push_back(b);
    }

    auto start = high_resolution_clock::now();
    quickSort(Vn, 0, N - 1);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Quick sort time: " << duration.count() << " ms" << endl;


}