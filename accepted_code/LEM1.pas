uses crt,math;
var r: array[1..10000] of real;
    n: integer;
    Rx,S: real;
 
procedure enter;
var i: integer;
begin
    readln(n); s:=0;
    for i:=1 to n do begin read(r[i]); s:=s+r[i] end;
end;
 
function check(k: real): real;
var v: real;
    i: integer;
begin
    check:=0;
    for i:=1 to n-1 do
      begin
        v:=(sqr(r[i]+k)+sqr(r[i+1]+k)-sqr(r[i]+r[i+1]))/(2*(r[i]+k)*(r[i+1]+k));
        v:=arccos(v);
        check:=check+v;
      end;
    v:=(sqr(r[n]+k)+sqr(r[1]+k)-sqr(r[n]+r[1]))/(2*(r[n]+k)*(r[1]+k));
    v:=arccos(v);
    check:=check+v;
end;
 
procedure process;
var l,r,mid,v: real;
begin
    l:=0; r:=s; mid:=(l+r)/2;
    while (mid<>l) and (mid<>r) do
      begin
        v:=check(mid);
        if v>=2*pi then l:=mid else r:=mid;
        mid:=(l+r)/2;
      end;
    write((l+r)/2:0:3);
end;
 
begin
clrscr;
   // assign(input,'x.inp'); reset(input);
       enter;
       process;
    //close(input);
end.