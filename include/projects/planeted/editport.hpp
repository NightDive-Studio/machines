/*
 * E D I T P O R T . H P P
 * (c) Charybdis Limited, 1998. All Rights Reserved
 */

/*
    PedPortalEditor

    A brief description of the class should go in here
*/

#ifndef _PLANETED_EDITPORT_HPP
#define _PLANETED_EDITPORT_HPP


#include "base/base.hpp"
#include "mathex/point2d.hpp"
#include "ctl/vector.hpp"
#include "ctl/pvector.hpp"
#include "planeted/editpoly.hpp"

class PedDomainEditor;

class PedPortalEditor	: public PedPolygonEditor
// Canonical form revoked
{
public:
    PedPortalEditor( );
    ~PedPortalEditor( void );

    void CLASS_INVARIANT;

	virtual void processInput( const DevButtonEvent& );
	// PRE( pSceneManager_ != NULL );
	// PRE( pPlanet_ != NULL );

	virtual void displayKeyboardCtrls( void );

	virtual void displayModeInfo( void );

	virtual void readCspFile( const SysPathName& );
	// PRE( cspFileName.existsAsFile() );

	virtual void writeCspFile( std::ofstream& );

	virtual void validate();

	void domainEditor( PedDomainEditor* );

protected:
	virtual PedPolygon* createPolygon( const PolyVerticies& verticies, MATHEX_SCALAR height, bool selected ) const;
	virtual PedPolygon* createDefaultPolygon() const;
	virtual void processVertexRight( void );
	virtual void processVertexLeft( void );
	virtual void processVertexUp( void );
	virtual void processVertexDown( void );
	virtual void updatePolygon( void );

private:
	void processCreatePortalsFromDomains( void );

	// Operations deliberately revoked
    PedPortalEditor( const PedPortalEditor& );
    PedPortalEditor& operator =( const PedPortalEditor& );
    bool operator ==( const PedPortalEditor& );

    friend ostream& operator <<( ostream& o, const PedPortalEditor& t );

	// Data...
	PedDomainEditor* pDomainEditor_;
};

#endif

/* End EDITPORT.HPP *************************************************/
