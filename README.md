# Engineering-Capstone Arduino Files

## Some git commands to know. First open your terminal, navigate to a folder you created where you will store these files locally.

## If you know you're the only one working on the code at a given moment:

<ol>
    <li>Git clone (only have to do this once per repo)</li>
    <li>git pull origin main (updates your local repository with latest code in github)</li>
    <li>git switch main (make sure you're on main)</li>
    <li>git add .</li>
    <li>git commit -m "describe what you changed"</li>
    <li>git push origin main</li>
</ol>

## If you're working at the same time as someone:

<ol>
    <li>Git clone (only have to do this once per repo)</li>
    <li>git pull origin main (updates your local repository with latest code in github)</li>
    <li>git switch -c branch_name</li>
    <li>Make code changes</li>
    <li>Git add .</li>
    <li>Git commit -m “description of changes made”</li>
    <li>Git switch main</li>
    <li>git pull origin main</li>
    <li>Git merge branch_name</li>
    <li>Git push origin main</li>
</ol>
