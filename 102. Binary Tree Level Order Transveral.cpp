/** Was pretty good at solving this problem, however I do need to improve my recursion logic.
 *  It's still a little unintuitive. Just need to practise these types of questions more.
 **/


class Solution {
	public:
		vector<int> ans;

		vector<vector<int>> levelOrder(TreeNode* root) {
			transverseTree(root, 0);
			return ans;
		}

		void transverseTree(TreeNode *node, int level) {
			if(node == NULL) return;

			if(ans.size() < level + 1) ans.push_back(vector<int>(1, node->val));
			else ans[level].push_back(node->val);

			transverseTree(node->left, level + 1);
			transverseTree(node->right, level + 1);

			return;
		}
};
