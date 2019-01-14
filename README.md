# Http_TextQuery

download html from a http website
open html and find wanted text in it
text query is object oriented

eg.
Query("apple") // find text "apple"
~Query("banana") // find lines with no "banana"
(~Query("apple")) & (Query"banana") // find lines which have both "banana" and do not have "apple"
... | ... // find lines which has "apple" or "banana"
