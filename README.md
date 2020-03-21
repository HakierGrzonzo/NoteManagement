# NoteManagement
Program designed to help organise notes
Program works with folders Notes/ and Tmp/ after invocation reads categories 
from main file ( .md) and moves  content of Tmp/ directory to according sub directory in Notes/
usage: notatkor [-push] [-pull]
push - resolve directory and push to GitHub
pull - pull notes from GitHub
Example:
before:
/.
notatkor
  Tmp/
  Physics.Thermodynamics.Theory.Entropy.md
  Notes/
after:
/.
notatkor
  Tmp/
  Notes/
    Physics/
      Thermodynamics/
        Theory/
          Entropy.md
notatkor -pull [pulls notes from github]
