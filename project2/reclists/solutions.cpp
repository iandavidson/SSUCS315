// Assignment : Project 2
// File : solutions.cpp
// Author : Ian Davidson
// Date  : Spring 2017 

#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the 
// function-prototype to the solutions.hpp. The function-prototypes 
// for append and reverse are already in solutions.hpp.

list append( list p, list q )
{
     if( is_null( p ) ) return q;
     return cons( car(p), append( cdr(p), q ));
}

list reverse( list p )
{
     if( is_null(p) || is_atom(p) ) return p;
     return append( reverse( cdr(p) ), cons(car(p), null() )) ;
}

bool is_lat( list p)
// is_lat takes a non atomic list and return true if the list is a list(potentially empty),
// and only has atoms as recursive lists inside, list p must be definition 3 or 1 only.
{
  //basecase:
  if (is_null(p))
    return true;
  if (is_atom(car(p)))
    return is_lat(cdr(p));
  return false;
}  

bool member( list p, list q)
//p is an atom and q is a non atomic list. member returns true if p appears anywhere in q.
//if p is not an atom false is returned
{

  if (is_null(q) || ! is_atom(p))//basecase where false is returned when all elems have been searched.
    return false;

  if (! is_atom(car(q)))
    if (member(p, car(q)))//this part lets the function handle deep lists
      return true;

  //after this point car(q) has to be an atom
  if (eq(p, car(q)))
    return true;
  return member(p, cdr(q));

}

list last( list p)
//last returns the last element, list element "N", of a non-atomic, non-empty list.
// list must have at least one element to expect correct results
{

  if ( is_null(cdr(p))){
    if (is_atom(car(p))){
      return car(p);
    }else{
      return last(car(p));
    }
  }
  return last( cdr(p));
     
}

list list_pair( list p, list q)
//list_pair takes two lists of atoms of the same length ( you may check for an error if you lie or just bomb out)
// returns a list that consists of lists of two atoms each, which are the correstponding atoms paired up.
{
  if ( is_null(cdr(p)) && is_null(cdr(q)))//goes through if when both lists have 1 elem left, basecase
    return cons(append(p, q), null());

  //  return cons(cons(car(p), q), list_pair(cdr(p),cdr(q)));
  return cons(cons(car(p), cons(car(q), null())), list_pair(cdr(p), cdr(q))); 
    
    
}

list firsts( list p)
// firsts takes p as an arguement, a list whos elements are lists of atoms and returns a list
//which contains the first element from each of the lists.
// firsts( ( a b c) (d e f) (c d b a) ) ) = ( a d c)
{
  if ( is_null(cdr(p)))
    return null();
  
  if(! is_atom(car(p)))
    return cons(firsts(car(p)), firsts(cdr(p)));
  
  else
    return car(p);

}

list flat( list p)
//flat takes a non atomic list and returns a list which is the orignal
//list with the parenthesis removed, execpt outter set
{
  if ( is_null(cdr(p))){
    if ( is_atom(car(p))){
      return p;
    }else
      return flat(car(p));
  }
  if (! is_atom(car(p)))//recursive call to go inside car(p)
    return append(flat(car(p)),flat(cdr(p)));
	   
  //if (is_atom(car(p)))

  return cons(car(p),flat(cdr(p)));
  
}

bool two_the_same( list p, list q)
//two_the_same takes two non-atomic recursive lists and returns true if p and q contain at least
//one atom in common.
// recursive path: will call member on each atom going from left to right through p
// each recursive call will be used with car or cdr, either into a definition #3 list or
// if the first atom of p isnt in q.
// basecase: if p is null.
{
  if (is_null(p))
    return false;


  if ( is_atom(car(p))){
    if( member(car(p),q)){
      return true;
    }else
      return two_the_same( cdr(p), q);
    //by this point car(p) cant be an atom and p cant be null()
  }
  //rec call when car p isnt an atom
  if ( two_the_same(car(p), q))
    return true;

  return two_the_same( cdr(p), q);
    
}
  
bool equal(list p, list q)
//equal takes two arbitray recursive lists and determies if they are identical, that is the parentheses
// are all in the same place and the atoms agree as to place and name, this is an extension of eq()
{
  if ( is_null(p) && is_null(q))//both must be null at the same time to be equal
    return true;

  if ( is_null(p) || is_null(q))
    return false;
    
    
  if ( is_atom(car(p)) && is_atom(car(q))){
    if ( eq(car(p), car(q)))//doesnt work if these arent atoms
      return equal(cdr(p), cdr(q));
  }else if (!is_atom(car(p)) && !is_atom(car(q))){ //bad cases to return false: if one is an atom and the other isnt
    if ( equal(car(p),car(q)))
      return equal(cdr(p),cdr(q));
    //case where car(p) and car(q) are not both atoms
  }
  return false;
}
  
list total_reverse(list p)
//This function takes a recursive list and returns the mirror image of that list.
{
  if (is_null(cdr(p)))
    return p;

  if (is_atom(car(p)))
    return cons(total_reverse(cdr(p)),cons(car(p),null()));

  return cons(total_reverse(cdr(p)),total_reverse(car(p)));
}

list shape(list p)
//This function should take a list and extract all the atoms, and return the list.
{
  if (is_null(p))
    return null();

  if (is_atom(car(p)))
    return shape(cdr(p));

  // car of p is not an atom.
  return append(cons(shape(car(p)),null()), shape(cdr(p)));
  
}

list intersection(list p, list q)
//p and q are lists of atoms with no atom appearing twice in p and no atom appearing twice in q.
//p and q represent sets, intersection should return the intersection of sets p and q.
// if nothing is in common between the two a null list will be returned.
//shallow lists only
{
  if ( is_null(p))
    return null();

  if( member(car(p), q))
    return append(cons(car(p),null()), intersection(cdr(p), q));

  return intersection(cdr(p), q);
}

list list_union(list p, list q)
// list_union forms the set which is their union. If p and q have an atom in common
// then it will only occur once in the union. If duplicates of atoms appear in p, q or both,
// function will return only one corresponding atom.
//Function works by checking car of p against the rest of p, and q.
//When P is null, the function is then called with q in the place of list p
//shallow lists as params only
{
  if (is_null(p)){
    if (is_null(q)){
      return null();
    }else{
      return list_union(q, p);
    }
  }
  if(member(car(p), cdr(p)) || member(car(p), q))
    return list_union(cdr(p),q);

  return cons(car(p), list_union(cdr(p), q));
}


list permute(list p)//extra credit

  
//p is a list of atoms. permute returns a list whose elements are lists of atoms,
//each of which is a different permutation
// shallow list required
// List passed must contain atleast 2 elems.
//ex: p = ( a b c); returned : ( ( a b c) (a c b) (b..)  (b..) (c..) (c..) )
// doesnt work at this point
{
  //psuedo
  /*
  //when list strickly only has 2 elems left
  if (is_null(cdr(cdr(p))))
    return append(cons(p,null()),cons(append(cdr(p),cons(car(p),null())),null()));
    // if given ( a b ) -> return this: ( ( a b ) ( b a ) )


  //works for more than 2 elements past this point.

  list permutations = new list(null());
  list remainder = new list(p);
  list previous = new list(null());
  
  //define permutations, list to be returned at end.
  //define list remainder = p;  breaking down
  //define list previous = null(); building up

  while (! is_null(remainder)){

    list current = new list(car(remainder));
    //current =  car from remainder

    
    //remainder => cdr(remainder)

    //cons, previous list to remainder of list.
    // then rec call permute(^^)
    // add current to elements returned. cons into permutations
    
    
    //previous => append(previous, current)

  }

  delete current;
  delete permute;
  delete remainder;
  delete previous;
  // delete statements for heap declarations
  
  //return permutations;
  return permutations;
  */
}
