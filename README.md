# Chess
chess + 8 queens problem

нереальная помойка

Вывод из main:

main:
```
int main(void)
{	
    Board* b = new Board(8);
    b->PlacePiece("a1", new Pawn(Black));
    std::cout<<*b;
    b->MovePiece("a1", "d4");
    std::cout<<*b;
}
```

```
8 □ ■ □ ■ □ ■ □ ■
7 ■ □ ■ □ ■ □ ■ □
6 □ ■ □ ■ □ ■ □ ■
5 ■ □ ■ □ ■ □ ■ □
4 □ ■ □ ■ □ ■ □ ■
3 ■ □ ■ □ ■ □ ■ □
2 □ ■ □ ■ □ ■ □ ■
1♟ □ ■ □ ■ □ ■ □
 A B C D E F G H

Moved from: a1 to: d4

8 □ ■ □ ■ □ ■ □ ■
7 ■ □ ■ □ ■ □ ■ □
6 □ ■ □ ■ □ ■ □ ■
5 ■ □ ■ □ ■ □ ■ □
4 □ ■ □ ♟□ ■ □ ■
3 ■ □ ■ □ ■ □ ■ □
2 □ ■ □ ■ □ ■ □ ■
1 ■ □ ■ □ ■ □ ■ □
 A B C D E F G H
```
