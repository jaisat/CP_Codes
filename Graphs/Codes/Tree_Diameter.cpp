#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
pair<int,int> Diameter(TreeNode* root){
	pp p;
	if(root == NULL){
		return {0,0};
	}
	pp left = Diameter(root->left);
	pp right = Diameter(root->right);

	p.first = max(left.first,right.first) + 1;
	p.second = max(left.second,max(right.second,left.first + right.first + 1));

	return p; 
}
int main(){

}