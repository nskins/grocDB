# grocDB

The process of compiling a grocery list is arduous and boring. Handwritten lists are unorganized and, in practice, have the user running back and forth between aisles in a jumbled frenzy. Wouldn't it be great if there was a swift and relatively effortless mechanism for generating structured, comprehensive grocery lists?

Well now there is! Say goodbye to running 5Ks in the supermarket...

...and say hello to grocDB! grocDB reads <a href="https://github.com/nskins/grocDB/wiki/Recipe-File-Format">specially-formatted recipe files</a>. whose information is stored into a database - the recipe data can then be retrieved at any time for insertion into a sorted grocery list.

## How to Use

**Read files**: 

-r Pizza.txt Spaghetti.txt

**Compile grocery list**: 

-w Pizza Spaghetti

**Remove recipe data from database**: 

-d Pizza Spaghetti
