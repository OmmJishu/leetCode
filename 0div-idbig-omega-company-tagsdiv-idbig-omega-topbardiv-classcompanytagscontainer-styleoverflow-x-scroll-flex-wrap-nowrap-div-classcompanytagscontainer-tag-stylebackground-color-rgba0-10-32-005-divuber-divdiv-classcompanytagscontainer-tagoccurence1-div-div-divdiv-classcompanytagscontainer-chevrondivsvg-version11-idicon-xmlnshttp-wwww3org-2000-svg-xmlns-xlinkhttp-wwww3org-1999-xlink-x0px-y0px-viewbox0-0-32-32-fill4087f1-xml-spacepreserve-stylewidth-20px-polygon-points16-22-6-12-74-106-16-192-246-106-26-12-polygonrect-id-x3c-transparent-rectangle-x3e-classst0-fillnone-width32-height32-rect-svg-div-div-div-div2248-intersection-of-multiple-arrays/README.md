<h2><a href="https://leetcode.com/problems/intersection-of-multiple-arrays/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Uber</div><div class="companyTagsContainer--tagOccurence">1</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2248. Intersection of Multiple Arrays</a></h2><h3>Easy</h3><hr><div>Given a 2D integer array <code>nums</code> where <code>nums[i]</code> is a non-empty array of <strong>distinct</strong> positive integers, return <em>the list of integers that are present in <strong>each array</strong> of</em> <code>nums</code><em> sorted in <strong>ascending order</strong></em>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [[<u><strong>3</strong></u>,1,2,<u><strong>4</strong></u>,5],[1,2,<u><strong>3</strong></u>,<u><strong>4</strong></u>],[<u><strong>3</strong></u>,<u><strong>4</strong></u>,5,6]]
<strong>Output:</strong> [3,4]
<strong>Explanation:</strong> 
The only integers present in each of nums[0] = [<u><strong>3</strong></u>,1,2,<u><strong>4</strong></u>,5], nums[1] = [1,2,<u><strong>3</strong></u>,<u><strong>4</strong></u>], and nums[2] = [<u><strong>3</strong></u>,<u><strong>4</strong></u>,5,6] are 3 and 4, so we return [3,4].</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [[1,2,3],[4,5,6]]
<strong>Output:</strong> []
<strong>Explanation:</strong> 
There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= sum(nums[i].length) &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i][j] &lt;= 1000</code></li>
	<li>All the values of <code>nums[i]</code> are <strong>unique</strong>.</li>
</ul>
</div>