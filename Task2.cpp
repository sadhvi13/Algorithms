#include <iostream>
#include <climits>
#include <vector>

using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
int task1()
{
   vector<int> a;
   int s;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
	   cin>>s;
	   a.push_back(s);
   }
    
    int maxSum =  INT_MIN;   //Note the usage of an inbuilt JS function to find min of an array.
	int l = 0;int r = 0;
    //int n = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k < j + 1; k++) {
                sum = sum + a[k];
            }
			if(sum>maxSum){
			maxSum = sum;
			l = i;
			r = j;
			}
            maxSum = max(maxSum, sum);
        }
    }
    cout<<l+1<<" "<<r+1<<" "<<maxSum<<endl;;
    return 0;
    
}

int task2(){
	// your code goes here
	vector<int> arr;
    int s;
	int n;
    cin>>n;
    for(int i=0;i<n;i++){
	   cin>>s;
	   arr.push_back(s);
    }
    int res[n];
    int count=0;
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        res[i] = INT_MIN;
    }
    int left,right;
    for(int i=0;i<n;i++){
        if(res[i]<arr[i]){
            res[i]=arr[i];
        }
        for(int j=i+1;j<n;j++){
            if(res[j]<(arr[j]+res[j-1])){
                res[j]=arr[j]+res[j-1];
            }
        }
    }
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        if(maxsum<res[i]){
            maxsum=res[i];
            
            right=i;
        }
    }
    
    if(maxsum == arr[right]){
        left=right;
    }
    else{
        int sum=maxsum;
        int i=right;
        while(sum!=0&&i>=0){
            sum=sum-arr[i];
            i--;
        }
        left=i+1;
    }
    cout<<endl;
    cout<<left+1<<" "<<right+1<<" "<<maxsum<<endl;
	return 0;
}

//=============================memoization
int maxval;
int maxSum(vector<int>& nums,vector<int>& memo, int i) {
	if (i == 0) {
		return nums[0];
	}
	if (memo[i] != INT_MIN) {
		return memo[i];
	}
	int res = max(nums[i], nums[i] + maxSum(nums,memo, i - 1));
	maxval = max(maxval, res);
	if(res>maxval){
			maxval = res;
			}
	memo[i] = res;
	return res;
}

int task3a() 
{
	vector<int> nums;
	int s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	   cin>>s;
	   nums.push_back(s);
	}
	vector<int> memo(nums.size(),INT_MIN);
        memo[0]=nums[0];
        if (nums.size() == 0) {
		return 0;
	    }
	    maxval = nums[0];
	    maxSum(nums, memo,nums.size()-1);
	    //==============================
	    int left;
	    int right;
	    int max=INT_MIN;
    for(int i=0;i<memo.size();i++){
        if(max<memo[i]){
            max=memo[i];
            
            right=i;
        }
    }
    
    if(max == nums[right]){
        left=right;
    }
    else{
        int sum=max;
        int i=right;
        while(sum!=0&&i>=0){
            sum=sum-nums[i];
            i--;
        }
        left=i+1;
    }
    left++;
    right++;
    cout<<left<<" "<<right<<" "<<maxval<<endl;
    
//======================
	    return 0;

}

int task3b() {
 
	vector < int > nums;
	int s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	   cin>>s;
	   nums.push_back(s);
   }
  	int maxSum = nums[0];
         int dp[n];
         dp[0] = nums[0];
         for (int i = 1; i < n; i++){
             maxSum = max(nums[i], maxSum + nums[i]);
             dp[i] = max(dp[i - 1], maxSum);
         }
         
    int maxsum=INT_MIN;
    int left,right;
    for(int i=0;i<n;i++){
        if(maxsum<dp[i]){
            maxsum=dp[i];
            
            right=i;
        }
    }
    
    if(maxsum == nums[right]){
        left=right;
    }
    else{
        int sum=maxsum;
        int i=right;
        while(sum!=0&&i>=0){
            sum=sum-nums[i];
            i--;
        }
        left=i+1;
    }
    

    cout<<left+1<<" "<<right+1<<" "<<maxsum<<endl;

         return 0;

}


void task4()
{
	// Stores the number of rows
	// and columns in the matrix
	int s,r,c;
	cin>>r>>c;
	vector<vector<int> > matrix(r,vector<int>(c,0));
   for(int i=0;i<r;i++){
	   for(int j=0;j<c;j++){
		   cin>>s;
			matrix[i][j] = s;
	   }
   }
	int top = 0;int left = 0;int bottom = 0;int right = 0;

	// Stores maximum submatrix sum
	int maxSubmatrix = 0;

	// Take each row as starting row
	for (int i = 0; i < r; i++) {

		// Take each column as the
		// starting column
		for (int j = 0; j < c; j++) {

			// Take each row as the
			// ending row
			for (int k = i; k < r; k++) {

				// Take each column as
				// the ending column
				for (int l = j; l < c; l++) {

					// Stores the sum of submatrix
					// having topleft index(i, j)
					// and bottom right index (k, l)
					int sumSubmatrix = 0;

					// Iterate the submatrix
					// row-wise and calculate its sum
					for (int m = i; m <= k; m++) {
						for (int n = j; n <= l; n++) {
							sumSubmatrix += matrix[m][n];
						}
					}

					// Update the maximum sum
					if(sumSubmatrix>maxSubmatrix){
						maxSubmatrix = sumSubmatrix;
						top = i;
						left = j;
						bottom = k;
						right =l;
					}
					
				}
			}
		}
	}

	// Print the answer
	cout << top+1<<" "<<left+1<<" "<<bottom+1<<" "<<right+1<<" "<<maxSubmatrix<<endl;
}


int task5()
{
    // base case
	int M,N,s;
	cin>>M>>N;
	vector<vector<int> > mat(M,vector<int>(N,0));
	for(int i=0;i<M;i++){
	   for(int j=0;j<N;j++){
		   cin>>s;
			mat[i][j] = s;
		}
	}
    
    if (mat.size() == 0) {
        return 0;
    }
 

 
    // `S[i][j]` stores the sum of submatrix formed by row 0 to `i-1`
    // and column 0 to `j-1`
    int S[M+1][N+1];
 
    // preprocess the matrix to fill `S`
    for (int i = 0; i <= M; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0 || j == 0) {
                S[i][j] = 0;
            }
            else {
                S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + mat[i-1][j-1];
            }
        }
    }
 
    int maxSum = INT_MIN;
    int rowStart, rowEnd, colStart, colEnd;
 
    // consider every submatrix formed by row `i` to `j`
    // and column `m` to `n`
    for (int i = 0; i < M; i++)
    {
        for (int j = i; j < M; j++)
        {
            for (int m = 0; m < N; m++)
            {
                for (int n = m; n < N; n++)
                {
                    // calculate the submatrix sum using `S[][]` in O(1) time
                    int submatrix_sum = S[j+1][n+1] - S[j+1][m] - S[i][n+1] + S[i][m];
 
                    // if the submatrix sum is more than the maximum found so far
                    if (submatrix_sum > maxSum)
                    {
                        maxSum = submatrix_sum;
                        rowStart = i;
                        rowEnd = j;
                        colStart = m;
                        colEnd = n;
                    }
                }
            }
        }
    }
 
    cout << "The maximum sum submatrix is\n\n";
    cout<<rowStart<<" "<<rowEnd<<" "<<colStart<<" "<<colEnd<<" "<<maxSum<<endl;
    /*for (int i = rowStart; i <= rowEnd; i++) {
        vector<int> row;
        for (int j = colStart; j <= colEnd; j++) {
            row.push_back(mat[i][j]);
        }
        printVector(row);
    }*/
 
    return 0;
}

int main(int arg_count, char *args[]){
	
	if(arg_count > 1){
	    string name(args[1]);
	    if(name == "1"){
	        task1();
	    }
	    else if(name == "2"){
	        task2();
	    }
		else if(name == "3a"){
		task3a();
	    }
	    else if(name == "3b"){
		task3b();
	    }
	    else if(name == "4"){
		task4();
	    }
	    else if(name == "5"){
		task5();
	    }
	   /* else if(name == "6"){
		task6();
	    }*/
	}
         else{
	        cout<<"no argument passed in command line";
	    }
	return 0;
}
