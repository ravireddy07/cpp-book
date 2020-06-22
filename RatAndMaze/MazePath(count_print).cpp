#include <iostream>
using namespace std;

int result = 0;

void countMazePath(int endrow, int endcol, int curr_row, int curr_col, string osf) {
	// base case
	if(curr_row == endrow and curr_col == endcol) {
		cout<<osf<<" ";
        result++;
		return ;
	}
	if(curr_row>endrow or curr_col>endcol) {
		return ;
	}
	countMazePath(endrow, endcol, curr_row+1, curr_col, osf+"V");
	countMazePath(endrow, endcol, curr_row, curr_col+1, osf+"H");
}

int main(int argc, char const *argv[])
{
	/* code */
	int row, col;
	cin>>row;
	cin>>col;
	countMazePath(row-1, col-1, 0, 0, "");
    cout<<endl<<result;
	return 0;
}
