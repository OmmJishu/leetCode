<h2><a href="https://leetcode.com/problems/number-of-boomerangs/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Google</div><div class="companyTagsContainer--tagOccurence">5</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>447. Number of Boomerangs</a></h2><h3>Medium</h3><hr><div><p>You are given <code>n</code> <code>points</code> in the plane that are all <strong>distinct</strong>, where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>. A <strong>boomerang</strong> is a tuple of points <code>(i, j, k)</code> such that the distance between <code>i</code> and <code>j</code> equals the distance between <code>i</code> and <code>k</code> <strong>(the order of the tuple matters)</strong>.</p>

<p>Return <em>the number of boomerangs</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> points = [[0,0],[1,0],[2,0]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> points = [[1,1],[2,2],[3,3]]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> points = [[1,1]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == points.length</code></li>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>All the points are <strong>unique</strong>.</li>
</ul>
</div>