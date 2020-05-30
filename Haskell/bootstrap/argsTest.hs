import System.Environment
import System.Exit
import Data.Char
import Numeric



getRule:: [String] -> Int
getRule (a:b:cx)
    | "--rule" == a = read b
getRule (a:b:cx) = getRule cx

getStart:: [String] -> Int
getStart (a:b:cx)
    | "--start" == a = read b
    | cx == [] = 0
getStart (a:b:cx) = getStart cx

getLines:: [String] -> Int
getLines (a:b:cx)
    | "--lines" == a = read b
    | cx == [] = 77680
getLines (a:b:cx) = getLines cx

getWindow:: [String] -> Int
getWindow (a:b:cx)
    | "--window" == a = read b
    | cx == [] = 80
getWindow (a:b:cx) = getWindow cx

getMove:: [String] -> Int
getMove (a:b:cx)
    | "--move" == a = read b
    | cx == [] = 0
getMove (a:b:cx) = getMove cx

readArgs:: [String] -> IO()
readArgs args = do
    let rule = getRule args
    let start = getStart args
    let lines = getLines args
    let window = getWindow args
    let move = getMove args
    launch rule start lines window move

main = do
    args <- getArgs
    case args of
        [] -> do
            putStrLn "[ERROR] No Arguments"
            exitWith (ExitFailure 84)
        _ -> do
            case length args  `mod` 2 of
                1 -> do
                    putStrLn "[ERROR] Bad Numbers Arguments"
                    exitWith (ExitFailure 84)
                0 ->
                    readArgs args

{-

(
Verifier si Arg vide
Si LENGTH (Arg) % 2 == 0


Créer une variable + une fonction pour chaque arguments (a:b:bx)

readInt() String -> Int
)



-}

{- >>= parse

parse ["-rule"] = usage >> exit

parse ["-start"] = version >> exit
-- parse ["-line"] = version >> exit
-- parse ["-window"] = version >> exit
-- parse ["-move"] = version >> exit

parse []     = noArgs >> dead
parse fs     = err >> dead

usage   = putStrLn "Usage: tac [-vh] [file ..]"
version = putStrLn "Haskell tac 0.1"

err   = putStrLn "[ERROR] Bad Arguments"
noArgs  = putStrLn "[ERROR] No Arguments"
exit    = exitWith ExitSuccess
dead     = exitWith (ExitFailure 84) -}