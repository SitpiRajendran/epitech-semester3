--
-- EPITECH PROJECT, 2020
-- bootstrap
-- File description:
-- myElem
--

myElem  :: Eq a => a -> [a] -> Bool
myElem a (b:bx)
    | a == b = True
    | bx == [] = False
myElem a (b:bx) = myElem a bx

safeDiv:: Int -> Int -> Maybe Int
safeDiv a b
    | b == 0 = Nothing
safeDiv a b = Just (a `div` b)

safeNth:: 