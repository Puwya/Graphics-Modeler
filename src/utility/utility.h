#pragma once
#include <QtCore/QString>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QtWidgets>
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <locale>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

#include "gm/gm.h"
#include "gm/vector.h"
#include "shapes.h"

namespace Utility {
// MAPPING - START
static const std::unordered_map<std::string, Qt::PenStyle> strToPenStyle(
    {{"NoPen", Qt::PenStyle::NoPen},
     {"SolidLine", Qt::PenStyle::SolidLine},
     {"DashLine", Qt::PenStyle::DashLine},
     {"DotLine", Qt::PenStyle::DotLine},
     {"DashDotLine", Qt::PenStyle::DashDotLine},
     {"DashDotDotLine", Qt::PenStyle::DashDotDotLine},
     {"CustomDashLine", Qt::PenStyle::CustomDashLine}});

static const std::unordered_map<std::string, Qt::PenCapStyle> strToPenCapStyle(
    {{"FlatCap", Qt::PenCapStyle::FlatCap},
     {"SquareCap", Qt::PenCapStyle::SquareCap},
     {"RoundCap", Qt::PenCapStyle::RoundCap},
     {"MPenCapStyle", Qt::PenCapStyle::MPenCapStyle}});

static const std::unordered_map<std::string, Qt::PenJoinStyle> strToPenJoinStyle(
    {{"MiterJoin", Qt::PenJoinStyle::MiterJoin},
     {"BevelJoin", Qt::PenJoinStyle::BevelJoin},
     {"RoundJoin", Qt::PenJoinStyle::RoundJoin},
     {"SvgMiterJoin", Qt::PenJoinStyle::SvgMiterJoin},
     {"MPenJoinStyle", Qt::PenJoinStyle::MPenJoinStyle}});

static const std::unordered_map<std::string, Qt::BrushStyle> strToBrushStyle(
    {{"NoBrush", Qt::BrushStyle::NoBrush},
     {"SolidPattern", Qt::BrushStyle::SolidPattern},
     {"Dense1Pattern", Qt::BrushStyle::Dense1Pattern},
     {"Dense2Pattern", Qt::BrushStyle::Dense2Pattern},
     {"Dense3Pattern", Qt::BrushStyle::Dense3Pattern},
     {"Dense4Pattern", Qt::BrushStyle::Dense4Pattern},
     {"Dense5Pattern", Qt::BrushStyle::Dense5Pattern},
     {"Dense6Pattern", Qt::BrushStyle::Dense6Pattern},
     {"Dense7Pattern", Qt::BrushStyle::Dense7Pattern},
     {"HorPattern", Qt::BrushStyle::HorPattern},
     {"VerPattern", Qt::BrushStyle::VerPattern},
     {"CrossPattern", Qt::BrushStyle::CrossPattern},
     {"BDiagPattern", Qt::BrushStyle::BDiagPattern},
     {"FDiagPattern", Qt::BrushStyle::FDiagPattern},
     {"DiagCrossPattern", Qt::BrushStyle::DiagCrossPattern},
     {"LinearGradientPattern", Qt::BrushStyle::LinearGradientPattern},
     {"RadialGradientPattern", Qt::BrushStyle::RadialGradientPattern},
     {"ConicalGradientPattern", Qt::BrushStyle::ConicalGradientPattern},
     {"TexturePattern", Qt::BrushStyle::TexturePattern}});

static const std::unordered_map<std::string, GM::ShapeType> strToShapeType(
    {{"Line", GM::ShapeType::Line},
     {"Polyline", GM::ShapeType::Polyline},
     {"Polygon", GM::ShapeType::Polygon},
     {"Rectangle", GM::ShapeType::Rectangle},
     {"Square", GM::ShapeType::Square},
     {"Ellipse", GM::ShapeType::Ellipse},
     {"Circle", GM::ShapeType::Circle},
     {"Text", GM::ShapeType::Text}});

static const std::unordered_map<std::string, Qt::AlignmentFlag> strToTextAlignment(
    {{"AlignLeft", Qt::AlignmentFlag::AlignLeft},
     {"AlignLeading", Qt::AlignmentFlag::AlignLeading},
     {"AlignRight", Qt::AlignmentFlag::AlignRight},
     {"AlignTrailing", Qt::AlignmentFlag::AlignTrailing},
     {"AlignHCenter", Qt::AlignmentFlag::AlignHCenter},
     {"AlignJustify", Qt::AlignmentFlag::AlignJustify},
     {"AlignAbsolute", Qt::AlignmentFlag::AlignAbsolute},
     {"AlignHorizontal_Mask", Qt::AlignmentFlag::AlignHorizontal_Mask},
     {"AlignTop", Qt::AlignmentFlag::AlignTop},
     {"AlignBottom", Qt::AlignmentFlag::AlignBottom},
     {"AlignVCenter", Qt::AlignmentFlag::AlignVCenter},
     {"AlignBaseline", Qt::AlignmentFlag::AlignBaseline},
     {"AlignVertical_Mask", Qt::AlignmentFlag::AlignVertical_Mask},
     {"AlignCenter", Qt::AlignmentFlag::AlignCenter}});

static const std::unordered_map<std::string, QFont::Style> strToFontStyle(
    {{"StyleNormal", QFont::Style::StyleNormal},
     {"StyleItalic", QFont::Style::StyleItalic},
     {"StyleOblique", QFont::Style::StyleOblique}});

static const std::unordered_map<std::string, QFont::Weight> strToFontWeight(
    {{"Thin", QFont::Weight::Thin},
     {"ExtraLight", QFont::Weight::ExtraLight},
     {"Light", QFont::Weight::Light},
     {"Normal", QFont::Weight::Normal},
     {"Medium", QFont::Weight::Medium},
     {"DemiBold", QFont::Weight::DemiBold},
     {"Bold", QFont::Weight::Bold},
     {"ExtraBold", QFont::Weight::ExtraBold},
     {"Black", QFont::Weight::Black}});
// MAPPING - END

namespace Debug {
void log(const std::string &msg);
}  // namespace Debug

namespace QT {
void getline(QTextStream &fin, std::string &value);
}

namespace Parser {
/**
 * @brief We give it a string and it gives us back
 * a hashed string.
 *
 * @param raw
 * @return std::size_t
 */
std::size_t parseHashKey(const std::string &raw);
/**
 * @brief Parses Shapes
 *
 * @param shapes
 */
void parseShapes(std::vector<std::unique_ptr<Shape>> &shapes, QTextStream &fin);

/**
 * @brief We are setting the specific porperties for each shape.
 * We are using QText tream instead of fstream because we are using a
 * functionality of QT called qrc loader.
 *
 * @param shapes
 * @param fin
 * @param id
 * @param type
 * @param index
 */
void deduceSpecifics(
    std::vector<std::unique_ptr<Shape>> &shapes, QTextStream &fin, const std::string &id,
    const std::string &type, const int &index);

/**
 * @brief Deducing the generic shape properties.
 * We are using QText tream instead of fstream because we are using a
 * functionality of QT called qrc loader.
 *
 * @param shapes
 * @param fin
 * @param type
 * @param index
 */
void deduceFields(
    std::vector<std::unique_ptr<Shape>> &shapes, QTextStream &fin,
    const std::string &type, const int &index);
}  // namespace Parser

namespace Login {
/**
 * @brief Validates login
 *
 * @param hash
 * @return true
 * @return false
 */
bool isValid(const std::size_t &hash);
}  // namespace Login
}  // namespace Utility
