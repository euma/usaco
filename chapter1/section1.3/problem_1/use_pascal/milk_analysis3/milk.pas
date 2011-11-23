program milk;

type pList = ^List;
    List = record
	farmer:longint;
	next:pList;
    end;
    HeadList = record
	head:pList;
	tail:pList;
    end;

    var fIn,fOut:text;
	sofar,i,x,want,cnt,a,b:longint;
	sorted,cost,amount:array[1..5010] of longint;
	csort:array[0..1010] of HeadList;

	t:pList;

begin
    assign(fIn,'milk.in');reset(fIn);
    assign(fOut,'milk.out'); rewrite(fOut);

    readln(fIn,want,cnt);
    for i:=1 to cnt do readln(fIn,cost[i],amount[i]);

	for i:=0 to 1000 do begin
	    new(csort[i].head);
	    csort[i].tail:=csort[i].head;
	    csort[i].head^.farmer:=-1;
	end;

	{Cast indexes into the array}
	for i:=1 to cnt do begin

	    t:=csort[cost[i]].tail;
	    if t^.farmer = -1 then t^.farmer:=i;
	    new(t^.next);
	    t^.next^.farmer:=-1;
	    csort[cost[i]].tail:=t^.next;
	end;

	{Pick indexes}
	x:=1;
	for i:=0 to 1000 do begin
	    t:=csort[i].head;
	    while t^.farmer > 0 do begin
	    sorted[x]:=t^.farmer;
	    inc(x);
	    t:=t^.next;
	end;
    end;

    sofar:=0;
    for i:=1 to cnt do begin
	if want < amount[sorted[i]] then begin
	    inc(sofar,want*cost[sorted[i]]);
	    want:=0; break;
	end

    else inc(sofar,amount[sorted[i]]*cost[sorted[i]]);
	dec(want,amount[sorted[i]]);
    end;

    writeln(fOut,sofar);
    close(fOut);
end.
