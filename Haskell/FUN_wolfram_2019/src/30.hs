--
-- EPITECH PROJECT, 2020
-- FUN_wolfram_2019
-- File description:
-- 30
--

module Rule30 where
import Tools

getLine30:: [Char] -> Int -> Int -> [Char]
getLine30 [] line win = []
getLine30 (a:b:c:dx) line win
    | dx == [] = elem
    | a == '*' && b == '*' && c == '*' = elem++" " ++ getLine30 (b:c:dx) line win
    | a == '*' && b == '*' && c == ' ' = elem++" " ++ getLine30 (b:c:dx) line win
    | a == ' ' && b == ' ' && c == ' ' = elem++" " ++ getLine30 (b:c:dx) line win
    | a == '*' && b == ' ' && c == '*' = elem++" " ++ getLine30 (b:c:dx) line win
--    | otherwise
    | a == '*' && b == ' ' && c == ' ' = elem++"*" ++ getLine30 (b:c:dx) line win
    | a == ' ' && b == '*' && c == '*' = elem++"*" ++ getLine30 (b:c:dx) line win
    | a == ' ' && b == '*' && c == ' ' = elem++"*" ++ getLine30 (b:c:dx) line win
    | a == ' ' && b == ' ' && c == '*' = elem++"*" ++ getLine30 (b:c:dx) line win
    where
        elem = []

is_new_30:: Int -> Int -> [Char] -> Int -> IO()
is_new_30 num start new win
    | num >= 1 = loop_30 new (num - 1) (start - 1) win
    | otherwise = putStr ""

loop_30:: [Char] -> Int -> Int -> Int -> IO()
loop_30 line num start win = do
    let new = " " ++ getLine30 line num win ++ " "
    printline num start new
    is_new_30 num start (new++" ") win

launch_30:: Int -> Int -> Int -> Int -> IO()
launch_30 start lines window move = do
    let firstline = createFirst window
    printline (lines + start - 1) start firstline
    loop_30 (firstline++" ") (lines + start - 1) start window