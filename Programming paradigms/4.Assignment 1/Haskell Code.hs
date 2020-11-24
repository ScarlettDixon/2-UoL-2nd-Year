--module Main where

import Data.List
import Data.Char
import System.IO
import qualified Data.Char as Char --Used to convert highlighted text to Capital

data TxtEdit = TxtEdit {l :: String, c:: String, r:: String, h::String} deriving (Show) 
-- leftSentence, cursorPosition, rightSentence, highlight_Editing
data ErrorChecking = Testing {a :: Int, s :: Int} deriving (Show)
-- cursorLocation, sentenceLength
--data FilePath
--setup :: TxtEdit -> TxtEdit -- Setup for further coding
--setup(TxtEdit{l = ls, r = rs, c = cl, s = sl, h = he}) = TxtEdit{l = "", r = getLine, c = 0, s = getline.Length, h = he}

initiate :: TxtEdit -- Initiate Text
initiate = (TxtEdit {l = "Text Editor",c = "|", r = "Test", h =""})

--init2 :: String --Test String initializing
--init2 = (conccurs(TxtEdit {l = "Text Editor",c = "|", r = " Test", h =""}))

--i3 :: String -> TxtEdit
--i3 ("Text Editor", "|", "Test", "") = (TxtEdit{l, c, r, h})

moveLeft :: TxtEdit -> TxtEdit -- Move Cursor Left
moveLeft (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = (reverse(tail (reverse ls))), c = cp,  r = [(head (reverse ls))] ++ rs, h = he})

moveRight :: TxtEdit -> TxtEdit -- Move Cursor Right
moveRight (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = ls ++ [(head rs)], c = cp,  r = (tail rs), h = he})

moveStart :: TxtEdit -> TxtEdit -- Move Cursor to the start
moveStart (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = "", c = cp, r = ls ++ rs, h = he})

moveEnd :: TxtEdit -> TxtEdit -- Move Cursor to the end
moveEnd (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = ls ++ rs, c = cp, r = "", h = he})

concatenate :: TxtEdit -> String -- Show Entire Sentence, concatenate left and right sentences into one
concatenate (TxtEdit{l = ls, r = rs}) = "Entire String: " ++ ls ++ rs

conccurs :: TxtEdit -> String -- Concatenate with cursor, will be used to possibly abstract code from user
conccurs (TxtEdit{l = ls, c = cp, r = rs }) = ls ++ cp ++ rs

charHighLeft :: TxtEdit -> TxtEdit --Highlight character left of the cursor
charHighLeft (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = (reverse(tail (reverse ls))), c = cp, r = rs, h = [(head (reverse ls))] })

charHighRight :: TxtEdit -> TxtEdit --Highlight character right of the cursor
charHighRight (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = ls, c = cp, r = (tail rs), h = [(head (reverse rs))] })

strHighLeft :: TxtEdit -> TxtEdit --Highlight string left of the cursor
strHighLeft (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = "", c = cp, r = rs, h = ls })

strHighRight :: TxtEdit -> TxtEdit --Highlight string right of the cursor
strHighRight (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = ls, c = cp, r = "", h = rs })

wordHighLeft :: TxtEdit -> TxtEdit --Highlight word left of the cursor
wordHighLeft (TxtEdit{l = [], c = cp, r = rs, h = he}) = (TxtEdit{l = [], c = cp, r = rs, h = he})
wordHighLeft (TxtEdit{l = ls, c = cp, r = rs, h = he}) = if ([head (reverse ls)]) == " "
then (TxtEdit{l = ls, c = cp, r = rs, h = he})
else wordHighLeft (TxtEdit{l = (reverse(tail (reverse ls))), c = cp, r = rs, h = [(head (reverse ls))] ++ he})

wordHighRight :: TxtEdit -> TxtEdit --Highlight word right of the cursor
wordHighRight (TxtEdit{l = ls, c = cp, r = [], h = he}) = (TxtEdit{l = ls, c = cp, r = [], h = he})
wordHighRight (TxtEdit{l = ls, c = cp, r = rs, h = he}) = if ([head rs]) == " "
then (TxtEdit{l = ls, c = cp, r = rs, h = he})
else wordHighRight (TxtEdit{l = ls, c = cp, r = (tail rs), h = he ++ [head rs]})

cut :: TxtEdit -> TxtEdit -- Cut highlighted item
cut (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = ls, c = cp, r = rs, h = he })

copy :: TxtEdit -> TxtEdit -- Copy highlighted item
copy (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = ls ++ he , c = cp, r = rs, h = he })

paste :: TxtEdit -> TxtEdit -- Paste highlighted item	
paste (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = ls ++ he , c = cp, r = rs, h = he })

backspace :: TxtEdit -> TxtEdit -- Delete character left of the cursor
backspace (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = (reverse(tail (reverse ls))), c = cp, r = rs, h = he})

del :: TxtEdit -> TxtEdit -- Delete character right of the cursor
del (TxtEdit{l = ls, c = cp, r = rs, h = he}) = (TxtEdit{l = ls , c = cp, r = (tail rs), h = he})
{-
setFile:: TxtEdit -> String -> IO () -- Puts String into a file
setFile (TxtEdit{l = ls, c = cp, r = rs, h = he}) = ls ++ rs = 

getFile:: FilePath -> IO String -- Pulls String from a file
getFile ("E:\\University Work") = [("Test")]
-}
{- 
http://learnyouahaskell.com/
https://www.newthinktank.com/2015/08/learn-haskell-one-video/
http://cheatsheet.codeslower.com/CheatSheet.pdf
http://hackage.haskell.org/package/ansi-terminal-0.8.0.2/docs/System-Console-ANSI.html
http://hackage.haskell.org/package/base-4.11.1.0/docs/Prelude.html#v:interact
http://learnyouahaskell.com/syntax-in-functions
http://learnyouahaskell.com/making-our-own-types-and-typeclasses
https://wiki.haskell.org/Introduction_to_Haskell_IO/Actions
https://www.youtube.com/watch?v=_dUW7iWs0No
-}

--TxtEdit {leftSide = "hell", rightSide = "o",cursorLocation = 3,sentenceLength = 5}
--let test1 = TxtEdit {leftSide = "hell", rightSide = "o",cursorLocation = 3,sentenceLength = 5}
--let test1 = TxtEdit {l = "hell", r = "o",c = 3,s = 5}
--let test1 = TxtEdit {l = "hell", r = "o",c = 3,s = 5, h =""}
--let test2 = TxtEdit {"hell", "o", 3, 5}


--import System.Console.ANSI.Types

{-main = do 
putStrLn("Test") 
get <- getLine

putStrLn ("Hello World " ++ get)
-}

{-Login = do
putStrLn("Welcome to the text editor, please login")

putStrLn("Username: ")
x <- readLn
if x == "John_0105" then 

putStrLn("Password: ")
-}
{-main = do
  setSGR [SetColor Foreground Vivid Red]
  setSGR [SetColor Background Vivid Blue]
  putStrLn "Red-On-Blue"
  setSGR [Reset]  -- Reset to default colour scheme
  putStrLn "Default colors."
-}
-- | Char Char Char Char | Char String String String
--data Txt = TxtEdit Char Char Char Char | TxtEdit String String String String


{-addChar :: TxtEdit -> TxtEdit
addChar (l h a x) = ((l++['q']) h a x)-}


--test :: TxtEdit -> String
--test (TxtEdit a b c d ) = a ++ " "
{-cursorMoveLeft :: TxtEdit -> TxtEdit
cursorMoveLeft(TxtEdit [] a b c) = TxtEdit [] a b c
cursorMoveLeft(TxtEdit l  a b c) = 
if head (reverse l) == '' && head(a++b) /= '' then TxtEdit l a b c
else cursorMoveLeft(CurseLeft(TxtEdit l a b c))								
-}