const
    x=20122007;
    fi='MYSTERY.inp';
    fo='MYSTERY.out';
type int64 = qword;

var
    n,i : longint;
    f : array[0..1000000] of longint;
    res : int64;
    e:text;

function getVal(a:longint):longint;
var
    p,q,i : longint;
    g : int64;
begin
    if a<=1000000 then exit(f[a])
    else
    begin
        p:=a mod 1000000;
        q:=a div 1000000;
        g:=f[p];
        for i:=1 to q do g:=(g*f[1000000]) mod x;
        exit(g);
    end;
end;

begin


    readln(n);

    f[0]:=1;
    for i:=1 to 1000000 do f[i]:=(f[i-1]*3) mod x;

    res:=1;
    if sqr(trunc(sqrt(n))) = n then
    begin
      for i:=1 to trunc(sqrt(n))-1 do
      if n mod i=0 then
      res:=(((res*(getVal(i)-1)) mod x)*(getVal(n div i)-1)) mod x;

      res:=(res*(getVal(trunc(sqrt(n)))-1)) mod x;
  end else
  begin
    for i:=1 to trunc(sqrt(n)) do
      if n mod i=0 then
        res:=(((res*(getVal(i)-1)) mod x)*(getVal(n div i)-1)) mod x;
  end;


    writeln(res);

end.
