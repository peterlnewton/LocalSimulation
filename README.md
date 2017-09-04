# [LocalSimulation](https://peterlnewton.com)

*Abstraction of Immediate Physx API used to create low cost Physics Simulations within Unreal Engine 4.*

This was made possible thanks to the work by 4.16 from UE4 Devs new Immediate Physics. 
https://www.unrealengine.com/en-US/blog/gdc-2017-making-physics-based-mayhem

Wouldn't be here without their work exposing PhysX API.

I've taken it a step further, and abtracted the implementation using a Blueprint Actor. Now you can control low level physics with just a few commands in Blueprint. :)

## Version
4.17.2 (Planned)
4.16.2 (Currently)

## Why
This was made to allow you to easily ignore world forces for physics simulations i.e. playing catch on a train. Imagine now you can play catch, and the simulation would respond in a way that the world isn't moving at all. Allowing for predictable results in environment that require this behavior.

## LocalSimulation
This plugin allows you to essentially create PxScene or Physic Scenes by placing an Actor called Local Simulation Volume, and adding other Static Mesh Components and soon Skeletal Mesh components within this Actor. Adding Constraints, and Forces will work as expected, but now with the additional layer of abstraction so that world simulation can be associated with a transform.

## TODO

# Skeletal Meshes
7/16/2017
>Solution ready for implementation. Transform issue was making joints impossible, which make Skeletal Meshes worthless. 
>Next push will contain first pass implementation of Skeletal Mesh Components.
>After that, I will slowly abstract the Blueprint commands further to support Mesh Components, to make use of this Actor much easier.
6/31/2017
>Tested plan yet to implement, but wanting a better solution.
>>Create bodies of Skeletal Mesh, then copy Skeletal Mesh to UPoseableMeshComponent. Map bodies to new
>>UPoseableMeshComponent and blend Animation from original Skeletal Mesh per bone as determiend by flag 
>>which says its 'Default/Kinematic/Simualted'.
		
# Transform / Scale
7/16/2017
>Appears this is because there is a ActorToBody offset that wasn't adjusted for. This has been affecting all aspects of Physics, but it is now rememedied.
>Scale issue continues to percist.

6/31/2017
>Appeared to get weird effects when scaling of components, but unable to decide exactly what is influencing it. Currently
>I believe it has to do with Static vs (Kinematic / Dynamic?). Still not 100% sure but really sketchy behavior which needs 
>to be made clear.
	
# Removing Joints / Acors
7/16/2017
>Everything has been solved. Unreal has a flipped frame of reference, and on top of the transform offset from the body. It wasn't clear what was happening with the joints. Now that is solved, next push will include polished integration of joints.
6/31/2017
>This works for the most part, but also needs to be reviewed.
	
# Adding Forces to Bodies / Simulation space.
7/16/2017
>R&D done. This will be imeplemented after the completely adaption of Sketal & Static rigidbodies. As abstracting the two components will make operations which they both will inevitability need, easier to use.
6/31/2017
>Need to make this possible.

# Updating Joints / Actors
7/16/2017
>This problem is now apparrent now that more things work as expected. That is happening is that in-between Physic Simuations aka where Contacts occur. Removing & Adding joints can introduce large amount of forces. 
>It would also be nice to have the ability to change from static, kinematic, and dynamic at runtime. Given this is an underlying proxy, this "should just work".
	
# Etc functions I'm not thinking of that are necessary.