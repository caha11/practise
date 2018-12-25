


vector<vector<int>> threeSum(<vector<int> &nums) {

	vector<vector<int>> ans;

	sort(nums.begin(), nums.end());

	for(int i = 0; i < nums.size(); i++) {

		
		int front = i + 1;
		int back = nums.size() - 1;

		while(front < back) {
			int sum = nums[i] + nums[start] + nums[end];
			if(sum == 0) {
				vector<int> triplet = vector<int>(3,0);
				triplet[0] = nums[i];
				triplet[1] = nums[start];
				triplet[2] = nums[end];
				front++;
				back--;
			if(sum < 0) front++;
			if(sum > 0) back--;
