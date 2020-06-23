# Alef - BurnZeZ Edition

This is a mirror of the work-in-progress port of the Alef programming language to 9front/386 by BurnZeZ. 

## Upstream changes

Upstream changes not yet commited an be found on the public grid griddisk at:

	- `/burnzez/rep/alef/root`
	- `/burnzez/alef`. 

Griddisk is accessible over 9p via `tcp!45.63.75.148!9564`. 

## Contributions

Forking is encouraged ☺. 

## Goals

Ideally, Alef should be able to be completely operable on modern 9front/386 and a non-destructive installation should be possible that makes Alef contained and not tightly coupled to full system installation. 

At the moment, Alef assumes it is just part of the shipped system install, like in 2e. 

## Installing

This is a destructive installation if you copy the root directories of this repository over `/`, so be careful. 

I recommend making a virtual machine specifically for working with Alef and cloning this tree, then `bind(1)`'ing the root directories over `/` with the `-b`. 

The `mkfile.diff` file is a patch for the `/sys/src/` mkfiles, allowing the system-vendored mkfiles be used to build Alef source code. 

### Building

Most directories should follow the basic rules for mkfiles:

- `mk` or `mk all` to build
- `mk install` to install
- `mk clean` to delete work files produced during compilation
- `mk nuke` to delete targeted files

The Alef compiler source is at `sys/src/alef`. 

The Alef documentation is at `sys/doc/alef` and `sys/man/1/alef`. 

## Plan9 Second Edition

To compare against Alef running on Plan9 second edition (2e), you can refer to the following for installing 2e in a virtual machine:

- https://seh.dev/plan9-2e/
- https://www.youtube.com/watch?v=W00TnQ91nj8

## Usage

The compiler is `8al(1)`. 

See [alef(1)](http://man.cat-v.org/plan_9_2nd_ed/1/alef) for more commands and information from 2e. 

## References

- http://man.cat-v.org/plan_9_2nd_ed/1/alef
- http://doc.cat-v.org/plan_9/2nd_edition/papers/alef/
- http://doc.cat-v.org/plan_9/2nd_edition/papers/alef/ref
- http://doc.cat-v.org/plan_9/2nd_edition/papers/alef/ug



