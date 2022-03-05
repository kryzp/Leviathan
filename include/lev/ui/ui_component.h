#pragma once

#include <lev/core/util.h>
#include <lev/containers/vector.h>
#include <lev/math/rect.h>
#include <lev/ui/ui_constraints.h>

namespace lev::gfx { class SpriteBatch; }

namespace lev::ui
{
	class UIComponent
	{
	public:
		UIComponent();
		virtual ~UIComponent();

		virtual void init();
		virtual void update();
		virtual void render(gfx::SpriteBatch& b);

		virtual bool mouse_hovering_over(bool include_children = true);
		virtual bool mouse_clicked_over(bool include_children = true);

		template <typename T, typename... Args>
		T* add(const UIConstraints& constraints, Args&&... args);

		//void add(Ref<UIComponent> component, const UIConstraints& constraints);
		void clear();

		RectI bounding_box() const;

		Vec2 position() const;
		Vec2 size() const;

		int x() const;
		void x(int x);

		int y() const;
		void y(int y);

		int width() const;
		void width(int w);

		int height() const;
		void height(int h);

		UIComponent* parent;
		UIConstraints constraints;
		bool enabled;
		float alpha;

	protected:
		bool mouse_clicked();

		RectI m_rect;
		Vector<UIComponent*> m_components;
	};

	template <typename T, typename... Args>
	T* UIComponent::add(const UIConstraints& constraints, Args&&... args)
	{
		T* component = new T(std::forward<Args>(args)...);
		component->parent = this;
		component->constraints = constraints;
		component->constraints.constrain(*component);
		component->init();
		m_components.push_back(component);
		return component;
	}
}
