--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- main
--

import System.Environment
import System.Exit
import Data.Char
import Numeric

import Arguments

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