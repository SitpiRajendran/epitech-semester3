--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- 90
--

module Rule90 where
import Tools

getLine90:: [Char] -> Int -> Int -> [Char]
getLine90 [] line win = []
getLine90 (a:b:c:dx) line win
    | dx == [] = elem
    | a == '*' && b == '*' && c == '*' = elem++" " ++ getLine90 (b:c:dx) line win
    | a == '*' && b == '*' && c == ' ' = elem++"*" ++ getLine90 (b:c:dx) line win
    | a == '*' && b == ' ' && c == '*' = elem++" " ++ getLine90 (b:c:dx) line win
    | a == '*' && b == ' ' && c == ' ' = elem++"*" ++ getLine90 (b:c:dx) line win
    | a == ' ' && b == '*' && c == '*' = elem++"*" ++ getLine90 (b:c:dx) line win
    | a == ' ' && b == '*' && c == ' ' = elem++" " ++ getLine90 (b:c:dx) line win
    | a == ' ' && b == ' ' && c == '*' = elem++"*" ++ getLine90 (b:c:dx) line win
    | a == ' ' && b == ' ' && c == ' ' = elem++" " ++ getLine90 (b:c:dx) line win
    where
        elem = []

is_new_90:: Int -> Int -> [Char] -> Int -> IO()
is_new_90 num start new win
    | num >= 1 = loop_90 new (num - 1) (start - 1) win
    | otherwise = putStr ""

loop_90:: [Char] -> Int -> Int -> Int -> IO()
loop_90 line num start win = do
    let new = " " ++ getLine90 line num win ++ " "
    printline num start new
    is_new_90 num start (new++" ") win

launch_90:: Int -> Int -> Int -> Int -> IO()
launch_90 start lines window move = do
    let firstline = createFirst window
    printline (lines + start - 1) start firstline
    loop_90 (firstline++" ") (lines + start - 1) start window