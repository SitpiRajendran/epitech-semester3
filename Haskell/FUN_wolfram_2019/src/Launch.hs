--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- Launch
--
module Launch where

import System.Environment
import System.Exit
import Data.Char
import Numeric
import Rule30
import Rule90
import Rule110

launch_error:: Int -> Int -> Int -> Int -> Int -> Int-> IO()
launch_error rule start lines window move error
    | error == 1 = do
        putStrLn "[ERROR] Wrong Argument"
        exitWith (ExitFailure 84)
    | rule < 0 = do
        putStrLn "[ERROR] No Rule or Bad Number"
        exitWith (ExitFailure 84)
    | start < 0 = do
        putStrLn "[ERROR] Bad Start Number"
        exitWith (ExitFailure 84)
    | lines < 0 = do
        putStrLn "[ERROR] Bad Lines Number"
        exitWith (ExitFailure 84)
    | window < 0 = do
        putStrLn "[ERROR] Bad Window Number"
        exitWith (ExitFailure 84)
    | rule == 30 =
        launch_30 start lines window move
    | rule == 90 =
        launch_90 start lines window move
    | rule == 110 =
        launch_110 start lines window move
    | otherwise = do
        putStrLn "[ERROR] Only Rule 30, 90 and 110 are accepted"
        exitWith (ExitFailure 84)
