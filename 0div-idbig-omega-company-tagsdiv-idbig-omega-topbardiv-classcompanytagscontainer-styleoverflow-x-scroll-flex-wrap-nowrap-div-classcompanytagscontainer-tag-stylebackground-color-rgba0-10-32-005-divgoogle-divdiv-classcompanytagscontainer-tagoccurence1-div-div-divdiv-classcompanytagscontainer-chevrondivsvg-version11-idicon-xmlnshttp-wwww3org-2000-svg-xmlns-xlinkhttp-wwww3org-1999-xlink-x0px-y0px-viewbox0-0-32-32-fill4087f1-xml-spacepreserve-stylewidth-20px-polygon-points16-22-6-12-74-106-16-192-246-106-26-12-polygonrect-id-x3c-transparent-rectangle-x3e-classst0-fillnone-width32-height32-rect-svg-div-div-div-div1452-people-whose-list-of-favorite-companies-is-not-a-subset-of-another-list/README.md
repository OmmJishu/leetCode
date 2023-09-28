<h2><a href="https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Google</div><div class="companyTagsContainer--tagOccurence">1</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1452. People Whose List of Favorite Companies Is Not a Subset of Another List</a></h2><h3>Medium</h3><hr><div><p>Given the array <code>favoriteCompanies</code> where <code>favoriteCompanies[i]</code> is the list of favorites companies for the <code>ith</code> person (<strong>indexed from 0</strong>).</p>

<p><em>Return the indices of people whose list of favorite companies is not a <strong>subset</strong> of any other list of favorites companies</em>. You must return the indices in increasing order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> favoriteCompanies = [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
<strong>Output:</strong> [0,1,4] 
<strong>Explanation:</strong> 
Person with index=2 has favoriteCompanies[2]=["google","facebook"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"] corresponding to the person with index 0. 
Person with index=3 has favoriteCompanies[3]=["google"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"] and favoriteCompanies[1]=["google","microsoft"]. 
Other lists of favorite companies are not a subset of another list, therefore, the answer is [0,1,4].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> favoriteCompanies = [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
<strong>Output:</strong> [0,1] 
<strong>Explanation:</strong> In this case favoriteCompanies[2]=["facebook","google"] is a subset of favoriteCompanies[0]=["leetcode","google","facebook"], therefore, the answer is [0,1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
<strong>Output:</strong> [0,1,2,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= favoriteCompanies.length &lt;= 100</code></li>
	<li><code>1 &lt;= favoriteCompanies[i].length &lt;= 500</code></li>
	<li><code>1 &lt;= favoriteCompanies[i][j].length &lt;= 20</code></li>
	<li>All strings in <code>favoriteCompanies[i]</code> are <strong>distinct</strong>.</li>
	<li>All lists of favorite companies are <strong>distinct</strong>, that is, If we sort alphabetically each list then <code>favoriteCompanies[i] != favoriteCompanies[j].</code></li>
	<li>All strings consist of lowercase English letters only.</li>
</ul>
</div>