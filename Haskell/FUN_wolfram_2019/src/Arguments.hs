--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- args
--
module Arguments where
import Launch

getRule:: [String] -> Int
getRule (a:b:cx)
    | "--rule" == a = read b
    | cx == [] = -10
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

verify_args:: [String] -> Int
verify_args (a:b:cx)
    | a /= "--rule" && a /= "--start" && a /= "--lines" && a /= "--window" && a /= "--move" = 1
    | cx == [] = 0
verify_args (a:b:cx) = verify_args cx

readArgs:: [String] -> IO()
readArgs args = do
    let rule = getRule args
    let start = getStart args
    let lines = getLines args
    let window = getWindow args
    let move = getMove args
    let error = verify_args args
    launch_error rule start lines window move error
