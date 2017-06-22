# [LocalSimulation](https://peterlnewton.com)

*Abstraction of Immediate Physx API used to create low cost Physics Simulations within Unreal Engine 4.*

This was made possible thanks to the work by 4.16 from UE4 devs. I needed isolated physics simulations in moving spaces, and so I created this.

## Why
This was made to allow you to easily ignore world forces for physics simulations i.e. playing catch on a train.

## LocalSimulation
This plugin allows you to essentially create PxScene or Physic Scenes by placing an Actor called Local Simulation Volume, and adding other Static Mesh Components and soon Skeletal Mesh components within this Actor. Adding Constraints, and Forces will work as expected, but now with the additional layer of abstraction so that world simulation can be associated with a transform.

## TODO

# Skeletal Meshes
>Tested plan yet to implement, but wanting a better solution.
>>Create bodies of Skeletal Mesh, then copy Skeletal Mesh to UPoseableMeshComponent. Map bodies to new
>>UPoseableMeshComponent and blend Animation from original Skeletal Mesh per bone as determiend by flag 
>>which says its 'Default/Kinematic/Simualted'.
		
# Transform / Scale
>Appeared to get weird effects when scaling of components, but unable to decide exactly what is influencing it. Currently
>I believe it has to do with Static vs (Kinematic / Dynamic?). Still not 100% sure but really sketchy behavior which needs 
>to be made clear.
	
# Removing Joints / Acors
>This works for the most part, but also needs to be reviewed.
	
# Adding Forces to Bodies / Simulation space. 
>Need to make this possible.
	
# Etc functions I'm not thinking of that are necessary.