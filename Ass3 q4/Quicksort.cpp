#include <iostream>
#include <vector>
using namespace std;

void swap(int& x, int& y) {
	int temp;
	temp = x;
	x = y;
	y = temp;

	return;
}

int Part(vector<int>& v, int start, int end) {

	int pivot = end;
	int a = start;
	for (int i = start; i < end; ++i) {
		if (v[i] < v[pivot]) {
			swap(v[i], v[a]);
			++a;
		}
	}
	swap(v[a], v[pivot]);
	return a;

}

void recursive(vector<int>& v, int start, int end) {

	if (start < end) {
		int w= Part(v, start, end);
		recursive(v, start, w - 1);
		recursive(v, w + 1, end);
	}

}
void quickSort(vector<int>& arr) {

	int start = 0;
	int end = arr.size() - 1;
	recursive(arr, start, end);

}

int main() {

	vector<int> vector{ 2,3,1,5,-10,20,19,1,3,2,11 };
	quickSort(vector);
	for (int i = 0; i < vector.size(); i++)
		cout << vector[i] << endl;
	return 0;
}