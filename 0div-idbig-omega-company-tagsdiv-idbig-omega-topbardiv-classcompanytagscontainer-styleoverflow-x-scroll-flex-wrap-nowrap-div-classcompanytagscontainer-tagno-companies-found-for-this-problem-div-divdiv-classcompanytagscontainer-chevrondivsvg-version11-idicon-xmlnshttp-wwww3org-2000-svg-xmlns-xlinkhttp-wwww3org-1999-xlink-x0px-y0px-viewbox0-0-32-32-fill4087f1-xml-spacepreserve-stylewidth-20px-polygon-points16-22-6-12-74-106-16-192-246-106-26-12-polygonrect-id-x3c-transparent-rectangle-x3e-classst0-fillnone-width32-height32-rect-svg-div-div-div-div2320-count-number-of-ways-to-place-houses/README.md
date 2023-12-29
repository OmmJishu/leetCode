<h2><a href="https://leetcode.com/problems/count-number-of-ways-to-place-houses/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2320. Count Number of Ways to Place Houses</a></h2><h3>Medium</h3><hr><div><p>There is a street with <code>n * 2</code> <strong>plots</strong>, where there are <code>n</code> plots on each side of the street. The plots on each side are numbered from <code>1</code> to <code>n</code>. On each plot, a house can be placed.</p>

<p>Return <em>the number of ways houses can be placed such that no two houses are adjacent to each other on the same side of the street</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>Note that if a house is placed on the <code>i<sup>th</sup></code> plot on one side of the street, a house can also be placed on the <code>i<sup>th</sup></code> plot on the other side of the street.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
Possible arrangements:
1. All plots are empty.
2. A house is placed on one side of the street.
3. A house is placed on the other side of the street.
4. Two houses are placed, one on each side of the street.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/05/12/arrangements.png" style="width: 500px; height: 500px;">
<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 9
<strong>Explanation:</strong> The 9 possible arrangements are shown in the diagram above.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>
</div>