// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIDRAW_H
#define	MOAIDRAW_H

#include <moaicore/MOAILua.h>

class MOAIAnimCurve;
class MOAITextureBase;

//================================================================//
// MOAIDraw
//================================================================//
/**	@name	MOAIDraw
	@text	Singleton for performing immediate mode drawing operations.
			See MOAIScriptDeck.
*/
class MOAIDraw :
	public MOAIGlobalClass < MOAIDraw, MOAILuaObject > {
private:

	//----------------------------------------------------------------//
	static int				_drawAnimCurve		( lua_State* L );
	static int				_drawAxisGrid		( lua_State* L );
	static int				_drawBoxOutline		( lua_State* L );
	static int				_drawCircle			( lua_State* L );
	static int				_drawEllipse		( lua_State* L );
	static int				_drawGrid			( lua_State* L );
	static int				_drawLine			( lua_State* L );
	static int				_drawPoints			( lua_State* L );
	static int				_drawRay			( lua_State* L );
	static int				_drawRect			( lua_State* L );
	static int				_fillCircle			( lua_State* L );
	static int				_fillEllipse		( lua_State* L );
	static int				_fillFan			( lua_State* L );
	static int				_fillRect			( lua_State* L );
	
	//----------------------------------------------------------------//
	static void			DrawLuaParams			( lua_State* L, u32 primType );
	static void			DrawLuaArray			( lua_State* L, u32 primType );

public:

	DECL_LUA_SINGLETON ( MOAIDraw )

	//----------------------------------------------------------------//
	static void			Bind					();
	static void			DrawAnimCurve			( const MOAIAnimCurve& curve, u32 resolution );
	static void			DrawAxisGrid			( USVec2D loc, USVec2D vec, float size );
	static void			DrawBoxOutline			( const USBox& box );
	static void			DrawEllipseFill			( const USRect& rect, u32 steps );
	static void			DrawEllipseFill			( float x, float y, float xRad, float yRad, u32 steps );
	static void			DrawEllipseOutline		( const USRect& rect, u32 steps );
	static void			DrawEllipseOutline		( float x, float y, float xRad, float yRad, u32 steps );
	static void			DrawGrid				( const USRect& rect, u32 xCells, u32 yCells );
	static void			DrawLine				( const USVec2D& v0, const USVec2D& v1 );
	static void			DrawLine				( const USVec3D& v0, const USVec3D& v1 );
	static void			DrawLine				( float x0, float y0, float x1, float y1 );
	static void			DrawLine				( float x0, float y0, float z0, float x1, float y1, float z1 );
	static void			DrawPoint				( const USVec2D& loc );
	static void			DrawPoint				( float x, float y );
	static void			DrawQuad				( const USQuad& quad );
	static void			DrawRay					( float x, float y, float dx, float dy );
	static void			DrawRectEdges			( USRect rect, u32 edges );
	static void			DrawRectFill			( USRect rect );
	static void			DrawRectFill			( float left, float top, float right, float bottom );
	static void			DrawRectOutline			( const USRect& rect );
	static void			DrawRectOutline			( float left, float top, float right, float bottom );
	static void			DrawVertexArray			( const USVec3D* verts, u32 count, u32 color, u32 primType );
	static void			DrawVertexArray2D		( const float* verts, u32 count, u32 color, u32 primType );
    static void         DrawPolygon             (const std::vector<USVec2D>& points);
    static void         DrawPolygonFilled       (const std::vector<USVec2D>& points);
						MOAIDraw				();
						~MOAIDraw				();
	void				RegisterLuaClass		( MOAILuaState& state );
};

#endif
