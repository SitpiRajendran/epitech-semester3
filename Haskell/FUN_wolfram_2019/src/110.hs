--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- 110
--

module Rule110 where
import Tools

getLine110:: [Char] -> Int -> Int -> [Char]
getLine110 [] line win = []
getLine110 (a:b:c:dx) line win
    | dx == [] && line < win = elem ++ " "
    | a == '*' && b == '*' && c == '*' = elem++" " ++ getLine110 (b:c:dx) line win
    | a == '*' && b == '*' && c == ' ' = elem++"*" ++ getLine110 (b:c:dx) line win
    | a == '*' && b == ' ' && c == '*' = elem++"*" ++ getLine110 (b:c:dx) line win
    | a == '*' && b == ' ' && c == ' ' = elem++" " ++ getLine110 (b:c:dx) line win
    | a == ' ' && b == '*' && c == '*' = elem++"*" ++ getLine110 (b:c:dx) line win
    | a == ' ' && b == '*' && c == ' ' = elem++"*" ++ getLine110 (b:c:dx) line win
    | a == ' ' && b == ' ' && c == '*' = elem++"*" ++ getLine110 (b:c:dx) line win
    | a == ' ' && b == ' ' && c == ' ' = elem++" " ++ getLine110 (b:c:dx) line win
    where
        elem = []

is_new_110:: Int -> Int -> [Char] -> Int -> IO()
is_new_110 num start new win
    | num >= 1 = loop_110 new (num - 1) (start - 1) win
    | otherwise = putStr ""

loop_110:: [Char] -> Int -> Int -> Int -> IO()
loop_110 line num start win = do
    let new = " " ++ getLine110 line num win ++ " "
    printline num start new
    is_new_110 num start new win

launch_110:: Int -> Int -> Int -> Int -> IO()
launch_110 start lines window move = do
    let firstline = createFirst window
    printline (lines + start - 1) start firstline
    loop_110 firstline (lines + start - 1) start window