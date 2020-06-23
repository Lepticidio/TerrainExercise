#include "stdafx.h"
#include "Navmesh.h"

Navmesh::Navmesh(const char* filename)
{
    TiXmlDocument doc(filename);
    if (!doc.LoadFile())
    {
        fprintf(stderr, "Couldn't read params from %s", filename);

    }
    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    pElem = hDoc.FirstChildElement().Element();
    if (!pElem)
    {
        fprintf(stderr, "Invalid format for %s", filename);

    }
    TiXmlHandle hRoot(pElem);
    TiXmlHandle hPolygons = hRoot.FirstChildElement("polygons");

    TiXmlElement* xPolygon = hPolygons.FirstChildElement("polygon").Element();
    while (xPolygon)
    {
        Polygon polygon;
        TiXmlElement* xPoint = xPolygon->FirstChildElement("point")->ToElement();
        while (xPoint)
        {
            USVec2D* pPoint = new USVec2D(0, 0);
            float fX = 0;
            float fY = 0;
            xPoint->Attribute("x", &fX);
            xPoint->Attribute("y", &fY);
            pPoint->mX = fX;
            pPoint->mY = fY;
            polygon.m_tVertex.push_back(*pPoint);

            TiXmlNode* xPointNode = xPoint->NextSibling();;
            if (xPointNode == nullptr)
            {
                xPoint = nullptr;
            }
            else
            {
                xPoint = xPointNode->ToElement();
            }

        }
        m_tPolygons.push_back(polygon);

        TiXmlNode* xPolygonNode = xPolygon->NextSibling();;
        if (xPolygonNode == nullptr)
        {
            xPolygon = nullptr;
        }
        else
        {
            xPolygon = xPolygonNode->ToElement();
        }
    }
}
void Navmesh::DrawDebug()
{
    MOAIGfxDevice& gfxDevice = MOAIGfxDevice::Get();
    gfxDevice.SetPenWidth(4);
    gfxDevice.SetPenColor(0.0f, 0.5f, 1.0f, 0.5f);
    for (int i = 0; i < m_tPolygons.size(); i++)
    {
        m_tPolygons[i].DrawDebug();
    }
}