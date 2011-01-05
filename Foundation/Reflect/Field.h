#pragma once

#include <map>

#include "Platform/Types.h"
#include "Platform/Utility.h"
#include "Foundation/Memory/SmartPtr.h"

#include "API.h"
#include "Enumeration.h"
#include "ReflectionInfo.h"

namespace Helium
{
    namespace Reflect
    {
        class Composite;

        namespace FieldFlags
        {
            enum Enum
            {
                Discard     = 1 << 0,       // disposable fields are not serialized
                Force       = 1 << 1,       // forced fields are always serialized
                Share       = 1 << 2,       // shared fields are not cloned or compared deeply
                Hide        = 1 << 3,       // hidden fields are not inherently visible in UI
                ReadOnly    = 1 << 4,       // read-only fields cannot be edited in the UI inherently
            };
        }

        class FOUNDATION_API Field : public ReflectionInfo, NonCopyable
        {
        public:
            REFLECTION_BASE( ReflectionTypes::Field );

        protected:
            Field(const Composite* composite);
            virtual ~Field();

        public:
            // protect external allocation to keep inlined code in this dll
            static Field* Create(const Composite* type);

            // creates a suitable serializer for this field in the passed object
            virtual DataPtr CreateData(Element* instance = NULL) const;

            // checks to see if the default value matches the value of this field in the passed object
            bool HasDefaultValue(Element* instance) const;

            // sets the default value of this field in the passed object
            bool SetDefaultValue(Element* instance) const;

            const Composite*        m_Composite;    // the type we are a field of
            tstring                 m_Name;         // name of this field
            uint32_t                m_Size;         // the size of this field
            uintptr_t               m_Offset;       // the offset to the field
            uint32_t                m_Flags;        // flags for special behavior
            uint32_t                m_Index;        // the unique id of this field
            const Type*             m_Type;         // the type of this field (NULL for POD types)
            const Class*            m_DataClass;    // type id of the serializer to use
            CreateObjectFunc        m_Creator;      // function to create a new instance for this field (optional)
        };

        typedef Helium::SmartPtr< Field > FieldPtr;
        typedef Helium::SmartPtr< const Field > ConstFieldPtr;
    }
}