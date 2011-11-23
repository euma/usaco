{
ID: your_id_here
PROG: test
LANG: PASCAL
}
Program Test;
Var fin, fout: text;
    a, b: word;
Begin
    Assign(fin, 'test.in'); Reset(fin);
    Assign(fout, 'test.out'); Rewrite(fout);
    Readln(fin, a, b);
    Writeln(fout, a+b);
    Close(fout);
End.
