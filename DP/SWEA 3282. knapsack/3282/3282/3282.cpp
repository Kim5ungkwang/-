#include <iostream>
#define endl '\n';

using namespace std;

int N;	//물건의 개수
int K;	//가방의 부피

void setMatrixVal(int y, int x);

// 물건
struct Item{
	int v;	//부피
	int c;	//가치
};

Item item[101];

//첫번째 인덱스 물건, 두번째 인덱스 부피 한계, 값 가치
int matrix[101][1001];

void init() {
	for (int i = 0; i < 101; i++) {
		matrix[i][0] = 0;
	}
	for (int i = 0; i < 1001; i++) {
		matrix[0][i] = 0;
	}
}

// N은 물건 개수
void input(int N) {
	int n;	//입력 받을 물건의 부피
	int k;	//입력 받을 물건의 가치
	for (int i = 1; i <= N; i++) {
		cin >> n >> k;
		item[i].v = n;
		item[i].c = k;
	}
}

void sol() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= K; x++) {
			setMatrixVal(y, x);
		}
	}
}

//x는 부피 한계, y는 물건
void setMatrixVal(int y, int x) {
	matrix[y][x] = 0;
	if (item[y].v <= x) {
		matrix[y][x] = item[y].c + matrix[y - 1][x - item[y].v];
	}
	matrix[y][x] = max(matrix[y][x], matrix[y - 1][x]);
}

void output(int testCase) {
	cout << '#' << testCase << ' ';
	cout << matrix[N][K] << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;

	for (int testCase = 0; testCase < T; testCase++) {

		cin >> N >> K;

		input(N);
		sol();
		output(testCase + 1);
	}
	return 0;
}