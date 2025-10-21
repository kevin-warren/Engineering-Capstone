# Engineering-Capstone Arduino Files

## Some git commands to know. First open your terminal, navigate to a folder you created where you will store these files locally.

<h3>If you know you're the only one working on the code at a given moment:</h3>
<ol>
  <li>git clone &lt;repo-url&gt; <em>(only have to do this once per repo)</em></li>
  <li>git pull origin main <em>(updates your local repository with the latest code)</em></li>
  <li>git switch main <em>(make sure you're on main)</em></li>
  <li>Make code changes</li>
  <li>git add . <em>(stages all modified/new files)</em></li>
  <li>git commit -m "describe what you changed"</li>
  <li>git push origin main <em>(uploads your changes to GitHub)</em></li>
</ol>

<h3>If you're working at the same time as someone:</h3>
<ol>
  <li>git clone &lt;repo-url&gt; <em>(only have to do this once per repo)</em></li>
  <li>git pull origin main <em>(updates your local repository with the latest code)</em></li>
  <li>git switch -c branch_name <em>(create and switch to a new branch)</em></li>
  <li>Make code changes</li>
  <li>git add .</li>
  <li>git commit -m "description of changes made"</li>
  <li>git switch main</li>
  <li>git pull origin main <em>(get the latest updates before merging)</em></li>
  <li>git merge branch_name <em>(merge your changes into main)</em></li>
  <li>git push origin main <em>(push merged updates to GitHub)</em></li>
</ol>
