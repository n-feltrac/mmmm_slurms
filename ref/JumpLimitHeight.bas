''*****************************************************************************
''
''	Platformer tutorial 101
''
''	Chapter 01-E
''  Limiting jump height ala Super Mario 
''
''  ARROWS = Movement
''  SPACE = Jump
''
''	Relminator (Richard Eric M. Lope)
''	http://rel.phatcode.net
''
''	Plotting the graph of jumping
''
''  I'm using EASY GL2D for rendering.
'' 	So try to read these tutorials for Easy GL2D..
'' 	http://back2basic.phatcode.net/?Issue_%232:Basic_2D_Rendering_in_OpenGL_using_Easy_GL2D%3A_Part_1
'' 	http://back2basic.phatcode.net/?Issue_%232:Basic_2D_Rendering_in_OpenGL_using_Easy_GL2D%3A_Part_2
''
''*****************************************************************************

#include once "fbgfx.bi"
#include once "/gl/gl.bi" 
#include once "/gl/glu.bi"   

#include once "FBGL2D.bi"     	'' We're gonna use Hardware acceleration
#include once "FBGL2D.bas"		'' So we'll be using my LIB



''*****************************************************************************
const as integer SCREEN_WIDTH = 640
const as integer SCREEN_HEIGHT = 480


const as integer FALSE = 0
const as integer TRUE = not FALSE

'' Play with these values for kicks
const as single GRAVITY = 0.75		'' Gravity to pull object downwards
const as single JUMPHEIGHT = 15		'' Height of the jump 

const as integer FLOOR_VALUE = 400  '' Our arbitrary floor value for collision purposes


''*****************************************************************************
'' Our main sub
''*****************************************************************************
sub main()

	dim as integer Frame = 0
	 
	GL2D.ScreenInit( SCREEN_WIDTH, SCREEN_HEIGHT )   ''Set up GL screen
	GL2D.VsyncON()
	
	Dim as integer Speed = 2			'' Horizontal speed
	dim as single x = 50				'' X Position  
	dim as single y = FLOOR_VALUE		'' Y Position
	dim as single Dx = 0				'' X velocity
	dim as single Dy = 0				'' Y velocity
	dim as integer CanJump = FALSE
	dim as integer Jumping = FALSE
	
	do
		
		Frame += 1						'' 
    	
    	Dx = 0  '' Set speed to 0
		
		'' If we pressed left then we walk negatively
		if multikey(FB.SC_LEFT) then 
			Dx = -speed
		EndIf
		
		'' See comments above
	    if multikey(FB.SC_RIGHT) then 
	    	Dx = speed
	    EndIf
    
    	'' Jump if we are pressing space
    	if multikey(FB.SC_SPACE) then 
		    if( CanJump ) then			'' Only jump if we "CanJump"
		    	Dy = -JUMPHEIGHT		'' This makes us jump
		    	CanJump = FALSE			'' We can't jump while Jumping
		    	Jumping = TRUE			'' Set jump flag to true 
		    end if
    	else		'' We stopped pressing space so...
    		if( Jumping ) then  '' Limit height if we are jumping
    			if( Dy < 0 ) then	'' only limit height when we are "going up"
    				Dy = 0
    			EndIf
    		EndIf
    	EndIf
    
    	Dy += GRAVITY 					'' pull the object downwards
    	
    	x += Dx							'' Move Horizontaly
		y += Dy							'' Move Vertically
		
		
		if( y + Dy > FLOOR_VALUE ) then 		'' Bounce if we hit the floor
			y = FLOOR_VALUE
			Dy = 0
			Jumping = FALSE						'' We stopped jumping
			if( not multikey(FB.SC_SPACE) ) then CanJump = TRUE  '' Only jump of we released Space
		EndIf
		
		GL2D.ClearScreen()
			
		GL2D.Begin2D()
			
			'' Draw the floor
			GL2D.BoxFilled( 0, FLOOR_VALUE, SCREEN_WIDTH, SCREEN_HEIGHT, GL2D_RGBA(255,255,255,255) )
			
			'' Draw the object
			GL2D.CircleFilled( x, y - 10, 10, GL2D_RGBA(0,255,255,255) )
			
			GL2D.PrintScale(0,  10, 1, "CONTROLS")    
			GL2D.PrintScale(0,  20, 1, "ARROWS = Move")    
			GL2D.PrintScale(0,  30, 1, " SPACE = Jump")    
	    	GL2D.PrintScale(0,  50, 1, "Pressing SPACE longer makes you jump higher.")    
	    		
		GL2D.End2D()
		
		
		dim as integer FPS = GL2D.LimitFPS(60)
		
		sleep 1,1
		flip
		
	Loop until multikey(FB.SC_ESCAPE)

	GL2D.ShutDown()
	
End Sub

''*****************************************************************************
''*****************************************************************************


main()


end







