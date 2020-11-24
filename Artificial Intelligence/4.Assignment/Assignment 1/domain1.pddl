; Domain Assignment1 1 for cleaning floor regions with one cleaner
; A domain file for CMP2020M assignment 1 2017/2018

; Domain definition
(define (domain domain-template1) ; It ill not work if another domain name is used as the problem code is linked to this domain name

    ; We require some typing to make the code easier to read but it is not technically necessary.
    (:requirements :typing)

    ; We have two types: cleaners and the regions, both are objects
    (:types cleaner region - object)

    ; Define all the predicates that can be used in the problem files
    (:predicates  

    ; Described what region a cleaner is at
    (cleaner-at ?c - cleaner ?x - region)

    ; Indicates that region ?x is above region ?y
    (above ?x - region ?y - region)

    ; Indicates that region ?x is below region ?y
    (below ?x - region ?y - region)

    ; Indicates that region ?x is right of region ?y
    (right ?x - region ?y - region)

    ; Indicates that region ?x is left of region ?y
    (left ?x - region ?y - region)
    
    ; Indicates that a region is cleaned
    (cleaned ?x - region)

    ; Indicates that a region is dirty
    (dirty ?x - region)

    )

 ; Define all actions that can be taken
 
 (:action suck ; The cleaner will clean this region
  :parameters (?r - cleaner ?x - region ?) ; One cleaner and one region as input
  :precondition (and (dirty ?x) (cleaner-at ?r ?x)) ; Location must be dirty and the cleaner must be located there
  :effect (and (cleaned ?x) (not(dirty ?x))) ; The location will be cleaned and so will no longer be dirty
 )
 (:action move_up ; Cleaner will move up
  :parameters (?r - cleaner ?x ?x2 - region) ; One cleaner and two regions as input
  :precondition (and (below ?x ?x2) ; To move up initial position has to be below the final.
		     (cleaner-at ?r ?x))  ; Robot must also be at position otherwise cleaner can clean without moving
  :effect (and (cleaner-at ?r ?x2) (not(cleaner-at ?r ?x))) ; Cleaner is at final position and no longer at initial
 )
  (:action move_down ; Cleaner will move down
  :parameters (?r - cleaner ?x ?x2 - region) ; One cleaner and two regions as input
  :precondition (and (above ?x ?x2) ; To move down initial position has to be above the final.
		     (cleaner-at ?r ?x)) ; Robot must also be at position otherwise cleaner can clean without moving
  :effect (and (cleaner-at ?r ?x2) (not(cleaner-at ?r ?x))) ; Cleaner is at final position and no longer at initial
 )
  (:action move_left ; Cleaner will move left
  :parameters (?r - cleaner ?x ?x2 - region) ; One cleaner and two regions as input
  :precondition (and (right ?x ?x2) ; To move left initial position has to be right of the final.
		     (cleaner-at ?r ?x)) ; Robot must also be at position otherwise cleaner can clean without moving
  :effect (and (cleaner-at ?r ?x2) (not(cleaner-at ?r ?x))) ; Cleaner is at final position and no longer at initial
 )
  (:action move_right ; Cleaner will move right
  :parameters (?r - cleaner ?x ?x2 - region) ; one cleaner and two regions as input
  :precondition (and (left ?x ?x2) ; To move right initial position has to be left of the final.
		     (cleaner-at ?r ?x))
  :effect (and (cleaner-at ?r ?x2) (not(cleaner-at ?r ?x))) ; Cleaner is at final position and no longer at initial
 )
)

; References:

; AIPS-98 Planning Competition Commitee (1998) PDDL - The Planning Domain Definition Language.
; Available from http://homepages.inf.ed.ac.uk/mfourman/tools/propplan/pddl.pdf [accessed 30 April 2018]

; Helmert, M.(undated) An introduction to PDDL. 
; Available from https://www.cs.toronto.edu/~sheila/2542/w09/A1/introtopddl2.pdf [accessed 20 April 2018].

; Russell, S and Norvig, P. (1998) Artificial Intelligence: A Modern Approach, 2nd edition. 
; Harlow: Pearson Education.

; University of Maryland (undated) Formal specifications using PDDL. 
; Available from https://www.cs.umd.edu/~atif/Teaching/Spring2003/Slides/5.pdf [accessed 25 April 2018].